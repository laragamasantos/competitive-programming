#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int valor;
    while(cin >> valor){
        if(valor%2 == 0)
            cout << 0 << endl;
        else 
            cout << 1 << endl;
    }

    return 0;
}