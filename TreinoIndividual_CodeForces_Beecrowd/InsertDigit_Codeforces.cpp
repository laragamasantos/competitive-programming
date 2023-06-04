
#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    unsigned long long int qntd, a=1;
    cin >> qntd;

    while(qntd--){
        unsigned long long int tam, valor, num, aux;
        cin>>tam>>valor>>num;
        vector<int> resp;
        for(int i=0; i<tam; i++){
            aux = num/powl(10,tam-a); //POTENCIA DE LONG DOUBLE
            num = abs(num-aux*powl(10,tam-a));
            resp.push_back(aux);
            a++;
        }

        for(int i=0; i<resp.size(); i++){
            if(valor > resp[i]){
                resp.insert(resp.begin()+i, valor);
                break;
            } else if(i == resp.size()-1){
                resp.insert(resp.begin()+i+1, valor);
                break;
            }
        }

        for(int i=0; i<resp.size(); i++){
            cout << resp[i];
        }
        cout << endl;
        a=1;
    }

    return 0;
}