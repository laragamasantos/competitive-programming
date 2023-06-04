#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    char num;
    string valor;
    int p;
    while(cin >> num){
    cin.ignore();
    getline(cin, valor);

    for(int i=0; i<valor.length(); i++){
        if(valor[i] == num){
            valor.erase(i);
        }
    }
    p = stoi(valor, nullptr, 10);
    cout << p << endl;
    }
    return 0;
}