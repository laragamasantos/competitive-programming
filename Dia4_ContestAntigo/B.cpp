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

bool palindromoBinario(ll num){
    string binario;
    bool palBin = false;
    while(1){
        binario.append(to_string(num%2));
        if(num/2 == 0)
            break;
        num = num/2;
    }
    if(binario.length() == 1)
        palBin = true;
    else{
        loop(i, 0, binario.length()/2){
            if(binario[i] == binario[binario.length()-1-i])
                palBin = true;
            else{
                palBin = false;
                break;
            }
        }
    }
    
    return palBin;
}

int32_t main(){ sws;
    ll qntd;
    cin>>qntd;
    while(qntd>0){
        unsigned int inf, sup, numPal=0, total=0;
        bool palDec = false, valido = false;
        string aux;
        cin>>inf>>sup;

        loop(i, inf, sup+1){
            palDec = false, valido = false;
            aux = to_string(i);
            if(aux.length() == 1){
                palDec = true;
            } else{
                loop(j, 0, aux.length()/2){
                    if(aux[j] == aux[aux.length()-1-j]){
                        palDec = true;
                    } else{
                        palDec = false;
                        break;
                    }
                }
            }
            if(palDec){
                valido = palindromoBinario(i);
            }
            if(valido){
                numPal++;
                total += i;
            }
        }
        qntd--;
        cout << total << ' ' << numPal << endl;
    }
    
    return 0;
}