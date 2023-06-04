#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int qntd, qntdPalavras, tamMusica;
    map<string, string> dicionario;
    string japones, portugues, linha, temp;
    vector<string> musica;
    cin >> qntd;

    while(qntd > 0){
        cin >> qntdPalavras;
        cin >> tamMusica;
        cin.ignore();
        
        for(int i=0; i<qntdPalavras; i++){
            getline(cin, japones);
            getline(cin, portugues);
            dicionario.insert(make_pair(japones, portugues));
        }

        for(int i=0; i<tamMusica; i++){
            getline(cin, linha);
            istringstream s (linha);
            while(getline(s, temp, ' '))
                musica.push_back(temp);
            for(int i=0; i<musica.size()-1; i++){
                if(dicionario.count(musica[i]) == 0)
                    cout << musica[i] << ' ';
                else{
                    auto aux = dicionario.find(musica[i]);
                    cout << aux->second << ' ';
                }
            }
            if(dicionario.count(musica[musica.size()-1]) == 0)
                cout << musica[musica.size()-1];
            else{
                auto aux = dicionario.find(musica[musica.size()-1]);
                cout << aux->second;
            }
            musica.clear();
            cout << endl;
        }
        cout << endl;
        dicionario.clear();
        qntd--;
    }
    return 0;
}

//imprimir dicionario
/*for(auto i=dicionario.cbegin(); i!=dicionario.cend(); ++i){
cout << i->first << '+' << i->second << endl;
}*/
