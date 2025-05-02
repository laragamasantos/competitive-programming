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
const int INF = 0x3f3f3f3f; //usado em problemas de prog dinamica
const ll LLINF = 0x3f3f3f3f3f3f3f3f; //escrevemos 3f 8 vezes
const double PI = acos(-1);

int alt=0, larg=0, x1Fin=0, y1Fin=0, x2Fin=0, y2Fin=0;

bool intersection(int x1, int y1, int x2, int y2){
    if (x1 >= x2Fin) return false;
    if (y1 <= y2Fin) return false;
    if (x2 <= x1Fin) return false;
    if (y2 >= y1Fin) return false;
    x1Fin = max(x1Fin, x1);
    y1Fin = min(y1Fin, y1);
    x2Fin = min(x2Fin, x2);
    y2Fin = max(y2Fin, y2);
    return true;
}

int32_t main(){ sws;
    int n, teste = 1;
    while(cin>>n){
        bool hasIntersec = true;
        alt = 0; larg = 0;
        if (n == 0) return 0;

        loop(i,0,n){
            int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
            if(alt == 0 && larg == 0){
                alt = y2 - y1;
                larg = x2 - x1;
                x1Fin = x1; y1Fin = y1; x2Fin = x2; y2Fin = y2;
            }
            else{
                hasIntersec = intersection(x1,y1,x2,y2);
            }
        }
        cout << "Teste " << teste << endl;
        if(hasIntersec){
            cout << x1Fin << ' ' << y1Fin << ' ' << x2Fin << ' ' << y2Fin << endl;
        } else {
            cout << "nenhum" << endl;
        }
        cout << endl;
        
        teste++;
    }
    return 0;
}