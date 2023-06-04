#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string palavra;
    cin >> palavra;

    string invertida;
    for(int i=0; i<palavra.length(); i++){
        invertida.insert(invertida.begin(), palavra[i]);
    }

    if(palavra == invertida){
        cout <<"sim" << endl;
    } else{
        cout <<"nao" << endl;
    }
   

    return 0;
}