#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int qntd, num;
    vector<int> valores;
    cin >> qntd;

    while(qntd > 0){
        cin >> num;
        if(count(valores.begin(), valores.end(), num) == 0){
            valores.push_back(num);
        }
        qntd--;
    }

    cout << valores.size() << endl;

    return 0;
}