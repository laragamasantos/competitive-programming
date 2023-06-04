#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    vector<char> alfab{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<char> input;
    char carac;
    for(int i=0; i<25; i++){
        cin >> carac;
        input.push_back(carac);
    }

    sort(input.begin(), input.end());
    for(int i=0; i<25; i++){
        if(alfab[i] != input[i]){
            cout << alfab[i] << endl;
            return 0;
        }
    }
    cout << 'z' << endl;
    return 0;
}