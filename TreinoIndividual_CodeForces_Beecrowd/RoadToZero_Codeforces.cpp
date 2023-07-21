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

int32_t main(){ sws;
    int n; cin>>n;

    while(n){
        int x, y, p1, p2, resp1=0, resp2 = 0;
        cin>>x>>y>>p1>>p2;

        if((x>0 && y>0)){
            if(x>y){
                resp1 = y*p2;
            } else{
                resp1 = x*p2;
            }
            resp1 += abs(x-y)*p1;
            resp2 = (x+y)*p1; 
        } else if (x<0 && y<0){
            if(x<y){
                resp1 = abs(y*p2);
            } else{
                resp1 = abs(x*p2);
            }
            resp1 += abs((x-y)*p1);
            resp2 = abs(x+y)*p1;
        } else{
            if(abs(x-0) < abs(y-0)){ //x mais prox de 0
                resp1 = abs(x*p2);
            } else{
                resp1 = abs(y*p2);
            }
            resp1 += abs(abs(y+x)*p1);
            resp2 = (abs(x)+abs(y))*p1;
        }
        if(resp1<resp2) cout << resp1 << endl;
        else cout << resp2 << endl;
        n--;
    }
    return 0;
}

