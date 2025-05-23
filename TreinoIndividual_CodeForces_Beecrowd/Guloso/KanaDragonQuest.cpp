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

int va(int x, int n) {
    return x/2 + 10;
}

int ls(int x, int m) {
    return x-10;
}

int32_t main(){ sws;
    int t; cin>>t;
    while(t>0){
        int x,n,m; cin>>x>>n>>m;

        while(n>0 || m>0){
            if(x<=0){
                break;
            }
            if (x>20 && n>0){
                x = va(x, n);
                n--;
            } else if(m>0) {
                x = ls(x,m);
                m--;
            } else {
                break;
            }
        }
        if(x<=0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;

        t--;
    }

    return 0;
}

