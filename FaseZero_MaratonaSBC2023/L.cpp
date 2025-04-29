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

int32_t main(){ sws;
    clock_t z = clock();
	
    int x, y, qntd, soma=0, temp=0;
    ld media;

    cin>>x>>y;

    cin>>qntd;

    loop(i, 0, qntd){
        temp = 0;
        int cordx, cordy, alc;
        cin>>cordx>>cordy>>alc;

        int aux1,aux2,aux3,aux4;

        aux1 = cordx - alc - 1;
        if(aux1 < 1) aux1 = 1;
        aux2 = cordx+alc-1;
        if(aux2>x) aux2 = x;

        aux3 = cordy - alc - 1;
        if(aux3 < 1) aux3 = 1;
        aux4 = cordy+alc-1;
        if(aux4>y) aux4 = y;

        temp = (aux2 - aux1)*(aux4-aux3);
        soma += temp;
    }

    

    media = soma / (x*y);

    cout << floor(media) << endl;

	//cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
    return 0;
}