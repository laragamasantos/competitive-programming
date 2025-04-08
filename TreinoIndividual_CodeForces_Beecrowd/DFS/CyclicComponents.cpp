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
const ll LLINF = 0x3f3f3f3f3f3f3f3f; //escrevemos 3f 8 vezes
const double PI = acos(-1);

const int MAX = 1e6+10; //numero max de vertices, nesse caso temos 10 elevado a 3

vector<vector<int>> g(MAX); //g[v] é a lista de vizinhos de v
vector<bool> vis(MAX); //indica se foi visitado
vector<bool> isCycle;

void dfs (int v){
	vis[v] = true;

    int size = g[v].size();
    if(size != 2){
        isCycle.back() = false;
    }

	for(auto w : g[v]){
        if(!vis[w]){
            dfs(w);
        }
    }
}

int32_t main(){ sws;
    int n,m; cin>>n>>m;

    loop(i,0,m){ //preenchendo a lista de vizinhos
        int v,u; cin>>v>>u; v--; u--;

        g[v].pb(u);
        g[u].pb(v);
    }

    int pos = 0;
    loop(i,0,n){
        if(!vis[i]){
            isCycle.pb(true);
            dfs(i);
        }
    }

    int cycles = 0;
    int isCycleSize = isCycle.size();
    loop(i,0,isCycleSize){
        if(isCycle[i]){
            cycles++;
        } 
    }

    cout<<cycles<<endl;

    return 0;
}

