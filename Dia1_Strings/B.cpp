#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    char letra;
    int cont=0;
    string frase;
    cin >> letra;
    cin.ignore();
    getline(cin, frase);

   if(islower(letra)){
        transform(frase.begin(), frase.end(), frase.begin(), ::tolower);
   } else{
        transform(frase.begin(), frase.end(), frase.begin(), ::toupper);
   }

    for(int i=0; i<frase.length(); i++){
        if(frase[i] == letra){
            cont++;
        }
    }

    cout << cont << endl;
    return 0;
}