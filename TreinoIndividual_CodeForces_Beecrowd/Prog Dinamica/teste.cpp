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
const int MAX = 1e3+5;
const int INF = 0x3f3f3f3f; //usado em problemas de prog dinamica
const ll LLINF = 0x3f3f3f3f3f3f3f3f; //escrevemos 3f 8 vezes
const double PI = acos(-1);

int32_t main(){ sws;
    int n,c,t1,t2;

    while(cin>>n>>c>>t1>>t2){
        int men = min(t1,t2), mai = max(t1,t2);
        vi h;
        loop(i,0,n){
            int f; cin>>f;
            h.pb(f);
        }

        int total1 = 0, dif = 0;
        for (int i=1; i<n; i++){
            dif += h[i] - h[i-1];
            if(dif >= mai){
                total1 += mai;
                dif = 0;
                i++;
            } 
            else if(dif >= men){
                total1 += men;
                dif = 0;
                i++;
            }
        }
        if(n%2 != 0) total1 += men;

        int total2 = men;
        dif = 0;
        for(int i=2; i<n; i++){
            dif += h[i] - h[i-1];
            if(dif >= mai){
                total2 += mai;
                dif = 0;
                i++;
            } 
            else if(dif >= men){
                total2 += men;
                dif = 0;
                i++;
            }
        }
        if(n%2 == 0){
            total2 += men;
        }
        
        cout << min(total1, total2) << endl;
    }
   
    return 0;
}