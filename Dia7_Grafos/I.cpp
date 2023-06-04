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

bool palindromo(int x){
    string aux = to_string(x);
    loop(i,0,aux.length()/2){
        if(aux[i] != aux[aux.length()-i-1])
            return false;
    }
    return true;
}

int32_t main(){ sws;
    int inf, sup;
    while(cin>>inf>>sup){
        bool pal = false;
        int menPal, maiPal;
        loop(i, inf+1, sup){
            if(palindromo(i)){
                menPal = i;
                pal = true;
                break;
                
            }
        }

        for(int i=sup-1; i>inf; i--){
            if(palindromo(i)){
                maiPal = i;
                pal = true;
                break;
                
            }
        }

        if(pal){
            cout << menPal << " " << maiPal << endl;
        } else{
            cout << "-1" << endl;
        }


    }
    
    return 0;
}