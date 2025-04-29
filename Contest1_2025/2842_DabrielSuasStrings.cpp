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

int scs_size[1010][1010];
string s, t;

int recupera(int i, int j){
    if(i>=s.size() and j>=t.size()) return 0;


    if(i>=s.size()){
        return t.size() - j;
    }

    if(j>=t.size()){
        return s.size() - i;
    }

    if(s[i] == t[j]){
        return 1 + recupera(i+1, j+1);
    }

    if(scs_size[i+1][j] < scs_size[i][j+1]) return 1 + recupera(i,j+1);
    return 1 + recupera(i+1, j);
}

int32_t main(){ sws;
    cin >> s >> t;

    for(int i = s.size()-1; i>=0; i--){
        for(int j=t.size()-1; j>=0; j--){
            if(s[i] == t[j]) scs_size[i][j] = 1 + scs_size[i+1][j+1];
            else scs_size[i][j] = max(scs_size[i+1][j], scs_size[i][j+1]);
        }
    }

    cout << recupera(0,0) << endl;
   
    return 0;
}