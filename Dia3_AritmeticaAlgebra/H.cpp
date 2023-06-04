#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    float qntd1, qntd2, soma=0, valor, resp;
    cin >> qntd1;
    qntd2 = qntd1;
    while(qntd1--){
        cin >> valor;
        soma += valor;
    }
    resp = soma/qntd2;
    cout << fixed << setprecision(2);
    cout << resp << endl;
    return 0;
}
