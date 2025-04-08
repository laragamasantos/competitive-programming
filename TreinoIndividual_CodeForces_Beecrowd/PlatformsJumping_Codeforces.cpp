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
    int w, num, dist; cin>>w>>num>>dist;
    int w1 = w, sum_plat=0;

    vi plat;
    vi resp;
    
    while(num){
        int aux; cin>>aux;
        plat.pb(aux);
        num--;
    }
    plat.pb(-2);

    loop(i,0,plat.size()-1){
        sum_plat+=plat[i];
    }
    
    resp.pb(-1);
    while(w){
        resp.pb(0);
        w--;
    }
    resp.pb(-2);
    
    if(dist >= w1){
        cout<<"YES"<<endl;
        int count2 = 1;
        loop(i,0,plat.size()){
            if(plat[i] == -2) break;
            while(plat[i] > 0){
                cout<<count2<<' ';
                plat[i]--;
            }
            count2++;
        }

        loop(i,0,w1-count2+1){
            cout<<0<<' ';
        }
        cout<<endl;
        return 0;
    }

    int count = 1, pos=0;
    bool var = false;
    loop(i,0,resp.size()){
        if(plat[pos] == -2){
           break;
        }
        
        int apagar = 0, x=0;
        if(resp.size()-i-2 <= sum_plat){
            var = true;
            break;
        } else{
            int aux = 0;
            while(plat[pos] > 0){
                resp[i+dist+aux] = count;
                plat[pos]--;
                sum_plat--;
                aux++;
            }
            i = i+dist+aux-2;
            //sum_plat -= count;
            count++;
            pos++;
        }
    }
    
    /*dbg(pos);
    dbg(plat[pos]);
    dbg(sum_plat);
    dbg(count);
    cout << resp.size()-sum_plat+0 << endl;*/
    
    int x=0;
    if(var){
        loop(i,pos,plat.size()-1){
            while(plat[pos] > 0){
                resp[resp.size()-sum_plat+x-1] = count;
                x++;
                plat[pos]--;
            }
            count++;
            pos++;
        }
    }

    int zeros = 0;
    loop(i,1,resp.size()-1){
        if(zeros >= dist){
            cout<<"NO"<<endl;
            return 0;
        }
        if(resp[i] == 0){
            zeros++;
        } else{
            zeros = 0;
        }
    }

    cout<<"YES"<<endl;
    loop(i,1,resp.size()-1){
        cout<<resp[i]<<' ';
    }
    cout<<endl;
    return 0;
}

