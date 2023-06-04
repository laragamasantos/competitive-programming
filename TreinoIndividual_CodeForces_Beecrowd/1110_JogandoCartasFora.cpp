#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);

    while(1){
        int qntd, valor=1, aux, tam;
        vector<int> seq;
        cin >> qntd;

        if(qntd == 0)
            return 0;

        cout << "Discarded cards: ";
        while(qntd > 0){
            seq.push_back(valor);
            valor++;
            qntd--;
        }
        
        tam = seq.size();
        while(tam > 2){
            cout << seq[0] << ", ";
            aux = seq[1];
            seq.erase(seq.begin(), seq.begin()+2); //apenas os elementos antes de seq.begin()+2 serão removidos,
                                                  //ou seja, não está incluso
            seq.push_back(aux);
            tam--;
        }
        cout << seq[0] << endl;
        seq.erase(seq.begin());
        cout << "Remaining card: " << seq[0] << endl;
    }

    return 0;
}