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
const int MAX = 1e6+5;
const int INF = 0x3f3f3f3f; //usado em problemas de prog dinamica
const ll LLINF = 0x3f3f3f3f3f3f3f3f; //escrevemos 3f 8 vezes
const double PI = acos(-1);

vector<vector<int>> g(MAX);
vector<vector<int>> pai(MAX);

void bfs(int s, int n){
    queue<int> q;
    vector<int> dist;
    q.push(s); 

    loop(i,0,n){
        dist.pb(INF);
    }
    dist[s] = 0;

    pai[s].pb(s);
    while(!q.empty()){
        int v = q.front(); q.pop();

        for(auto u : g[v]){
            if(dist[u] > dist[v] + 1){ //garante que nao foi visitado e é menor caminho
                pai[u].pb(v); 
                dist[u] = dist[v] + 1;
                q.push(u);
            }
            else if(dist[u] == dist[v] + 1){ //outra opção de menor caminho
                pai[u].pb(v); 
            }
        } 
    }
}

vector<int> parents(int v){
    vector<int> ret;

    //ret.pb(v);
    while(pai[v][0]!=v){
        int tam = pai[v].size();
        loop(i,0,tam){
            ret.pb(pai[v][i]);
        }
        v = pai[v][0];
    }

    return ret;
}

int32_t main(){ sws;
    int n,m,a,b; cin>>n>>m>>a>>b;

    loop(i,0,m){
        int x,y; cin>>x>>y;
        g[x].pb(y);
        g[y].pb(x);
    }

    bfs(0, n+1);

    vi teste = parents(b);

    loop(i,0,teste.size()){
        cout << teste[i] << ' ';
    }
    cout<<endl;
    
    return 0;
}