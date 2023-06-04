#include <bits/stdc++.h>
//Biblioteca com muitas funções 
using namespace std;
//Faz com que não seja necessário ter sempre a escrita std antes dos comandos 
int calcula(int valor)
{
 ios_base::sync_with_stdio(false);
 int result=1;
 if(valor > 1){
     valor = valor-1; 
     result = 5*(calcula(valor));
     return result;
    }
  else{
      return result*4;
  }
}

int main(){
	ios_base::sync_with_stdio(false);
    int valor;
    int result;
    while(cin >> valor)
    {
        if(valor == 1){
            cout << '5' << endl;
        }else if(valor > 5){
            cout << '0' << endl;
        }
        
        else{
        result = calcula(valor);
       cout << result <<endl;
        }
    }

}