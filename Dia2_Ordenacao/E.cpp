#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    string seq1;
    string seq2;
    cin >> seq1;
    cin >> seq2;

    sort(seq1.begin(), seq1.end());
    sort(seq2.begin(), seq2.end());

    if(seq1 == seq2)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    return 0;
}