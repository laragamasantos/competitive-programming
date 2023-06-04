#include <bits/stdc++.h>
using namespace std;
//alias comp='g++ -std=c++17 -g -O2 -Wall -Wconversion -Wshadow -fsanitize=address,undefined -fno-sanitize-recover -ggdb -o out'
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); //Melhora o desempenho
#define int long long //Melhor linha de codigo ja escrita
#define endl "\n" //Evita flush
#define loop(i,a,n) for(int i=a; i < n; i++)
#define input(x) for (auto &it : x) cin >> it
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define mp make_pair
#define TETO(a, b) ((a) + (b-1))/(b)
#define dbg(x) cout << #x << " = " << x << endl
#define print(x,y) loop(it,0,y){cout << x[it] << " ";} cout << "\n";
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef priority_queue<int, vector<int>, greater<int>> pqi;
const ll MOD = 1e9+7;
const int MAX = 1e4+5;
const ll LLINF = 0x3f3f3f3f3f3f3f3f; //escrevemos 3f 8 vezes
const double PI = acos(-1);

int32_t main(){ sws;
    unsigned int num, aux, div=0, temp=1;
    bool verdadeiro = false;

    while(cin >> num){
        temp=1; div=0; verdadeiro = false;
        if(num == 0){
            cout  << '0' << " " << '1' << " " << '2' << endl;
            verdadeiro = true;
        } else if(!verdadeiro){
            for(aux=2; aux<=sqrt(num); aux++){
                if(num%aux==0)
                    div++;
            }
        if(div==0)
            cout << "mensagem falsa" << endl;
        else{
            while(temp+2<=num/2){
                if(temp*(temp+1)*(temp+2) == num){
                    cout << temp << " " << temp+1 << " " << temp+2 << endl;
                    temp++;
                    verdadeiro = true;
                    break;
                }
                temp++;
            }
            if(!verdadeiro)
                cout << "mensagem falsa" << endl;
        }
        }
        
    }

    return 0;
}