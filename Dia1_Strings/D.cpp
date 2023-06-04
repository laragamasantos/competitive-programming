#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    
    while(1){
        int qntd, diferentes=1;
        vector <string> dna;
        string aux;
        cin >> qntd;
        cin.ignore();
        if(qntd == 0)   return 0;
        
        for(int i=0; i<qntd; i++){
            getline(cin, aux);
            sort(aux.begin(), aux.end());
            dna.push_back(aux);
            if(i>=1){
                if(dna[i] != dna[i-1]){
                    diferentes++;
                }
            }
        }
        cout << diferentes << endl;
    }

    return 0;
}