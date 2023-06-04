#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    unsigned long long int valor, resp=0;
    while(cin >> valor){
        resp = valor*(valor+1)/2 - 1 + 1;
        cout << resp << endl;
    }

    return 0;
}

//sum = y*(y+1)/2 – x*(x+1)/2 + x;