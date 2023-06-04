#include<bits/stdc++.h>
using namespace std;

//ATENCAO: EH NECESSARIO MUDAR OS TIPOS NOS PARAMETROS DAS FUNCOES
bool sortbysec(const tuple<string, char, int>& a, const tuple<string, char, int>& b){
        return (get<1>(a) < get<1>(b));
    }

bool sortbyth(const tuple<string, char, int>& a, const tuple<string, char, int>& b){
    return (get<2>(a) < get<2>(b));
}

int main(){
    ios_base::sync_with_stdio(false);
    int qntd, dist, j=0, k=0;
    string nome;
    char regiao;
    bool primeira = true;

    vector<tuple<string, char, int>> info;

    while(cin >> qntd){
        while(qntd > 0){
            cin >> nome;
            cin >> regiao;
            cin >> dist;
            info.push_back(make_tuple(nome, regiao, dist));
            qntd--;
        }

        stable_sort(info.begin(), info.end(), sortbyth); //distancia

        for(int i=0; i<info.size(); i++){
            if(primeira){
                j=i;
                k=i;
            }
            if(get<2>(info[i]) == get<2>(info[i+1])){
                j++;
                primeira = false;
            } else{
                stable_sort(info.begin()+k, info.begin()+j+1, sortbysec); //regiao
                primeira = true;
            }    
        }

        primeira = true;
        for(int i=0; i<info.size(); i++){
            if(primeira){
                j=i;
                k=i;
            }
            if(get<1>(info[i]) == get<1>(info[i+1]) && get<2>(info[i]) == get<2>(info[i+1])){
                j++;
                primeira = false;
            } else{
                stable_sort(info.begin()+k, info.begin()+j+1); //nome
                primeira = true;
            } 
        }
        
        for(int i=0; i<info.size(); i++){
            cout << get<0>(info[i]) << endl;
        }
        info.clear(); //eh necessario esvaziar o vector entre os diferentes casos de uso!!!
    }
   
    return 0;
}

//ordem alfabetica: L, N, O, S