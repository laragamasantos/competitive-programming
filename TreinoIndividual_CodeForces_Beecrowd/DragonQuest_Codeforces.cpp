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
    int qntd; cin>>qntd;
    int hp, n, m, prev;
    while(qntd>0){
        bool end = false;
        cin>>hp>>n>>m;

        while(n>0){
            if(hp<=0){
                cout << "YES" << endl;
                end = true;
                break;
            }
            prev = hp;
            hp = floor(hp/2) + 10;
            if(hp >= prev){
                hp = prev;
                break;
            }
            n--;
        }

        while(m>0){
            if(end) break;
            else if(hp<=0){
                cout << "YES" << endl;
                end = true;
                break;
            }
            hp = hp - 10;
            m--;
        }

        if(!end){
            if(hp>0) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        qntd--;
    }

    return 0;
}

