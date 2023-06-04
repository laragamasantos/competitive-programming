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

vector<vector<int>> g(MAX);
vector<bool> vis(MAX);

void dfs(int v){
    vis[v] = true;
    cout << v << " ";

    for(auto w : g[v]) if(!vis[w]){
        dfs(w);
    }
}

void bfs(int s) {
    queue<int> q;
    vector<bool> visBFS(MAX);

    cout << s << " ";

    q.push(s);
    visBFS[s] = 1;

    while(!q.empty()){
        int v = q.front();
        for(auto u : g[v]) {
            if(!visBFS[u]) {
                cout << u << " ";
                q.push(u);
                visBFS[u] = 1;
            }
        }
        q.pop();
     }
}

int32_t main(){ sws;
    int i, j;
    char lixo;
    while(cin>>i>>lixo>>j){
        g[i].push_back(j);
        g[j].push_back(i);
    }

    bfs(0);

    cout<<endl;

    dfs(0);

    return 0;
}