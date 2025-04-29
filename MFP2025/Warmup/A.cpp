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

int32_t main(){ sws;
    int xa,ya,xb,yb,xc,yc,xd,yd;
    cin>>xa>>ya>>xb>>yb>>xc>>yc>>xd>>yd;

    int larg, alt;

    if(xa == xb){
        alt = max(ya,yb) - min(ya,yb);
        larg = max(yc,yd) - min(yc,yd);
    } else if(xa == xc){
        alt = max(ya, yc) - min(ya,yc);
        larg = max(yb,yd) - min(yb,yd);
    } else if(xa == xd){
        alt = max(ya,yd) - min(ya,yd);
        larg = max(yb,yc) - min(yb,yc);
    } else if(xb == xc){
        alt = max(yb,yc) - min(yb,yc);
        larg = max(ya,yd) - min(ya,yd);
    } else if(xb == xd){
        alt = max(yb,yd) - min(yb,yd);
        larg = max(yc,ya) - min(yc,ya);
    } else if(xc == xd){
        alt = max(yc,yd) - min(yc,yd);
        larg = max(ya,yb) - min(ya,yb);
    }

    cout << larg * alt << endl;

    return 0;
}