#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string nome;
    string aux;
    vector<pair<string, string>> lista;

    while(getline(cin, nome)){
        aux = nome;
        for(int i=0; i<aux.length(); i++){
            
            if(!isalpha(aux[i]))
                remove(aux.begin(), aux.end(), aux[i]);
            aux[i] = tolower(aux[i]);
        }
        lista.emplace_back(aux, nome);
    }

    sort(lista.begin(), lista.end());

    for(int i=0; i<lista.size(); i++){
        cout << lista[i].second << endl;
    }

    return 0;
}