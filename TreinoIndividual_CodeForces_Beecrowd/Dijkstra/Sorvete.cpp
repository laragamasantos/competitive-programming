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
const int INF = 0x3f3f3f3f;
const ll LLINF = 0x3f3f3f3f3f3f3f3f; //escrevemos 3f 8 vezes
const double PI = acos(-1);
const int MAX = 1e6+10;

vector<pair<int,int>> g[MAX];
vector<int> amg, distOrig, distDest;

//vou precisar de dois dijkstras: do ponto inicial 1 até cada amigo
//e outro do ponto final N até cada amigo
void dijkstra(int n){
    priority_queue<pair<int,int>> pq1; //par(distancia, indice do vertice)
    priority_queue<pair<int,int>> pq2;

    distOrig[0] = 0;
    distDest[n-1] = 0;
    pq1.push(mp(0,0));
    pq2.push(mp(0,n-1)); //definimos na pq o nó do qual estou partindo na busca

    while(!pq1.empty()){
        int d = -pq1.top().ff, u = pq1.top().ss;
        pq1.pop();
        if(d > distOrig[u]) continue;
        for(auto pv: g[u]){
            if(distOrig[pv.ff] > distOrig[u] + pv.ss){
                distOrig[pv.ff] = distOrig[u] + pv.ss;
                pq1.push(mp(-distOrig[pv.ff], pv.ff));
            }
        }
    }

    while(!pq2.empty()){
        int d = -pq2.top().ff, u = pq2.top().ss;
        pq2.pop();
        if(d > distDest[u]) continue;
        for(auto pv: g[u]){
            if(distDest[pv.ff] > distDest[u] + pv.ss){
                distDest[pv.ff] = distDest[u] + pv.ss;
                pq2.push(mp(-distDest[pv.ff], pv.ff));
            }
        }
    }
}

int32_t main(){ sws;
    int n,m,x; cin>>n>>m>>x;

    loop(i,0,n){
        amg.pb(0);
        distOrig.pb(INF);
        distDest.pb(INF);
    }

    loop(i,0,m){
        int u,v,w; cin>>u>>v>>w; u--; v--;
        
        g[u].pb(mp(v, w));
        g[v].pb(mp(u, w));
    }

    loop(i,0,x){
        int a; cin>>a; a--;
        amg[a] = 1;
    } 

    dijkstra(n);

    int menor;
    loop(i,0,n){
        if(amg[i]){
            menor = min(menor, distOrig[i] + distDest[i]);
        }
    }

    cout << menor << endl;

    return 0;
}

