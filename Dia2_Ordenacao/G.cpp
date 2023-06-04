#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    vector<int> valores;
    int valor;
    int qntd;

    while(cin >> valor){
        valores.push_back(valor);
    }

    stable_sort(valores.begin(), valores.end());

    while(valores.size() > 0){
        qntd = count(valores.begin(), valores.end(), valores[0]);
        cout << valores[0] << ' ' << qntd << endl;
        valores.erase(valores.begin(), valores.begin()+qntd);
    }

    return 0;
}