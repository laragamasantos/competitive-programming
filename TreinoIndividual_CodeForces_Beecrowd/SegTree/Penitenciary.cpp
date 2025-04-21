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

vi seg(4*MAX,0);
vector<pair<int,int>> v;

int build(int p, int l, int r){
    if(l == r) return seg[p] = seg[p]+1;
    int m = (l+r)/2;
    return seg[p] = min(build(2*p, l, m), build(2*p+1, m+1, r));
}

int query(int a, int b, int p, int l, int r, int qntdG, int total){
    if(b < l or r < a) return 0;
    if(a <= l and r <= b){
        if(seg[p] == qntdG) return total = total + r-l+1;
        else return 0;
    } 
    int m = (l+r)/2;
    return total = query(a,b,2*p,l,m, qntdG, total) + query(a,b,2*p+1,m+1,r, qntdG, total);
}

int32_t main(){ sws;
    int n, q; cin>>n>>q;

    loop(i,0,n){
        int l,r; cin>>l>>r;
        v.pb(mp(l,r));
        build(1,l,r);
    }

    loop(i,0,q){
        char carac; cin>>carac;

        if(carac == 'C'){ //update
            int ind, l, r; cin>>ind>>l>>r;
            v[ind] = mp(l,r);
        } else{ //query
            int gi, gf; cin>>gi>>gf; gi--; gf--;
            int qntdG = gf - gi + 1;
            int total = query(gi, gf, 1, 0, n-1, qntdG, 0);
            cout << total << endl;
        }
    }
    return 0;
}