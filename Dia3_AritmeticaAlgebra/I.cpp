#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    float a, b, c, d, e, f, x, y;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    cin >> f;
    y = (a*f-d*c)/(a*e-d*b);
    x = (c-b*y)/a;
    cout << fixed << setprecision(2);
    cout << x << ' ' << y << endl;
    return 0;
}