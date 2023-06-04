#include <bits/stdc++.h>
#include <numeric>
using namespace std;

int mdc(int num1, int num2)
{
    if(num1%num2 == 0)
        return num2;
    else
        return mdc(num2, num1%num2);
}

int main(){
    ios_base::sync_with_stdio(false);
    vector<int> valores;
    int valor, resp;
    while(cin >> valor){
        valores.push_back(valor);
    }
    for(int i=0; i<valores.size(); i++){
        resp = mdc(valores[i], resp);
    }
    cout << resp << endl;
    return 0;
}