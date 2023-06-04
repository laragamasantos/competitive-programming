#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string music;
    vector<string> lista;

    while(getline(cin, music)){
        lista.push_back(music);
    }

    sort(lista.begin(), lista.end());
    for(int i=0; i<lista.size(); i++){
        cout << lista[i] << endl;
    }

    return 0;
}