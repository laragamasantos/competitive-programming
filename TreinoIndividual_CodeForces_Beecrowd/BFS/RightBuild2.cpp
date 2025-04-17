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

const int MAX = 2e5+10;

vector<vector<int>> g(MAX);
vector<bool> visA(MAX);
vector<bool> visB(MAX);
vector<int> paiA(MAX);
vector<int> paiB(MAX);

void bfsA(int s, int dest){
    queue<int> q;
    q.push(s); visA[s] = 1;

    paiA[s] = s;
    while(!q.empty()){
        int v = q.front(); q.pop();

        for(auto u : g[v]) {
            if(!visA[u]){
                q.push(u); visA[u]=1;
                paiA[u] = v;
                if(u == dest){
                    return;
                }
            }
        }
    }
}

void bfsB(int s, int dest){
    queue<int> q;
    q.push(s); visB[s] = 1;

    paiB[s] = s;
    while(!q.empty()){
        int v = q.front(); q.pop();

        for(auto u : g[v]) {
            if(!visB[u]){
                q.push(u); visB[u]=1;
                paiB[u] = v;
                if(u == dest){
                    return;
                }
            }
        }
    }
}

int pathSize(int a, int b){
    set<int> set;
    if(!visA[a] or !visB[b]) return 0;

    set.insert(a);
    while(paiA[a] != a){
        a = paiA[a];
        set.insert(a);
    }

    set.insert(b);
    while(paiB[b] != b){
        b = paiB[b];
        set.insert(b);
    }

    return set.size()-1;
}

int32_t main(){ sws;
    int n,m,a,b; cin>>n>>m>>a>>b;

    loop(i,0,m){
        int x,y;cin>>x>>y;

        g[x].pb(y);
        g[y].pb(x);
    }

    bfsA(0,a);
    bfsB(a,b);
    int tam1 = pathSize(a,b);

    fill(visA.begin(), visA.end(), false);
    fill(visB.begin(), visB.end(), false);
    fill(paiA.begin(), paiA.end(), -1);
    fill(paiB.begin(), paiB.end(), -1);

    bfsA(0,b);
    bfsB(b,a);
    int tam2 = pathSize(b,a);

    cout << min(tam1,tam2) << endl;

    return 0;
}

