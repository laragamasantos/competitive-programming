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
        int qntd; cin>>qntd;
        int sum = 0;
        vi seq;
        vi aux;
        while(qntd){
            int aux; cin>>aux;
            seq.pb(aux);
            qntd--;
        }

        //order all negative and positive subsequences
        aux.push_back(seq[0]);
        int size = 1, len = seq.size();
        for(int i=1; i<len; i++){
            if(seq[i]/abs(seq[i]) == seq[i-1]/abs(seq[i-1])){
                aux.push_back(seq[i]);
                size++;
            } else{
                sort(aux.begin()+aux.size()-size, aux.end());
                aux.push_back(seq[i]);
                size=1;
            }
        }
        sort(aux.begin()+aux.size()-size, aux.end());
    
        for(int i=1; i<len; i++){
            if(aux[i]/abs(aux[i]) != aux[i-1]/abs(aux[i-1]))
                sum += aux[i-1];
        }
        sum += aux[len-1];
        cout << sum << endl;
        n--;
    }
    return 0;
}

