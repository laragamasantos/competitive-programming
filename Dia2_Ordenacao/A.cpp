#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int valor;
    vector<int> vetor;
    while(cin >> valor){
        if(valor%2 != 0){
            if(count(vetor.begin(), vetor.end(), valor) == 0)
                vetor.push_back(valor);
        }
            
    }
    stable_sort(vetor.begin(), vetor.end());
    for(int i=0; i<vetor.size(); i++){
        cout << vetor[i] << endl;
    }

    return 0;
}