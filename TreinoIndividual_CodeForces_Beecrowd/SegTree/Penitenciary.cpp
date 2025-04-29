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
const int MAX = 1e6;
const int INF = 0x3f3f3f3f; //3f 4 vezes
const ll LLINF = 0x3f3f3f3f3f3f3f3f; //3f 8 vezes
const double PI = acos(-1);

vector<pair<int,int>> v(MAX);
vector<pair<int,int>> seg(4*MAX);

pair<int,int> build(int p, int l, int r){
    if (l == r) return seg[p] = v[l];
    int m = (l+r)/2;
    pair<int,int> left, right;
    left = build(2*p, l, m);
    right = build(2*p+1, m+1, r);
    return seg[p] = mp(max(left.ff, right.ff), 
                       min(left.ss, right.ss));
}

pair<int,int> query(int a, int b, int p, int l, int r){
    if (b < l or r < a) return mp(-INF, INF);
    if (a <= l and r <= b) return seg[p];
    int m = (l+r)/2;
    pair<int,int> left, right;
    left = query(a, b, 2*p, l, m);
    right = query(a, b, 2*p+1, m+1, r);
    return mp(max(left.ff, right.ff), 
              min(left.ss, right.ss));
}

pair<int,int> update(int i, pair<int,int> x, int p, int l, int r){
    if (i < l or r < i) return seg[p];
    if (l == r) return seg[p] = x;
    int m = (l+r)/2;
    pair<int,int> left, right;
    left = update(i, x, 2*p, l, m);
    right = update(i, x, 2*p+1, m+1, r);
    return seg[p] = mp(max(left.ff, right.ff), 
                       min(left.ss, right.ss));
}

int32_t main(){ sws;
    int n, q; cin>>n>>q;

    loop(i,0,n){
        int l,r; cin>>l>>r;
        v[i] = mp(l,r);
    }
    build(1,0,n-1);

    loop(i,0,q){
        char type; cin>>type;

        if (type == '?'){ //query
            int a,b; cin>>a>>b; a--; b--;
            pair<int,int> resp;
            resp = query(a, b, 1, 0, n-1);
            cout << max(resp.ss - resp.ff + 1, (long long)0) << endl;
        } 
        else { //update
            int j,a,b; cin>>j>>a>>b; j--;
            update(j, mp(a,b), 1, 0, n-1);
        }
    }
   
    return 0;
}