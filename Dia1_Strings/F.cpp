#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int qntd;
    string frase;
    cin >> qntd;
    cin.ignore();
    getline(cin, frase);

    for(int i=0; i<qntd; i++){
        cout << frase << endl;
    }

    return 0;
}