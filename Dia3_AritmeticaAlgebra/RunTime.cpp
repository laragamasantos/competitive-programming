#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define int            long long int
#define double         long double
#define endl           "\n"
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print_v(a)     for(auto x : a) cout << x << " "; cout << endl
#define print_vp(a)    for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl
#define f(i,s,e) 	   for(int i=s;i<e;i++)
#define rf(i,e,s) 	   for(int i=e-1;i>=s;i--)

const int INF = 0x7f3f3f3f;
const int MAX = 1e8+10; // 10⁶ + 10

template <typename Arg1> void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args> void __f (const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr (names + 1, ',');
	cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}


bool confere_um(vector<int> v) {
	for(int x : v) {
		if(x == 1) return true;
	}
	return false;
}

int encontra_min(vector<int> v) {

	int min = v[0];
	for(int x : v) {
		if(x < min) 
			min = x;
	}
	return min;
}

bool todos_diviz(vector<int> v, int i) {

	for(int x : v) {
		if(x % i != 0) return false;
	}
	return true;
}

void divide_todos_por_i(vector<int>& v, int i) {
	for(int& x : v) {
		x /= i;
	}
}

int mdc(vector<int> v)
{
    if(confere_um(v))
        return 1;

    for(int i=2; i <= encontra_min(v); i++)  // enquanto nao encontrar um numero que e divisivel por ambos
        if(todos_diviz(v, i)) {
			divide_todos_por_i(v,i);
            return i * mdc(v);
		}

    return 1;
}

void solve() {
	int n; 
	
	vector<int> v;

	while(cin >> n) {
		v.push_back(n);
	}	

	cout << mdc(v) << endl;
}

int32_t main() { _
	
	clock_t z = clock();


	int t = 1; // cin >> t;
	while (t--) solve();


	cerr << fixed << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << endl;
	return 0;
}

