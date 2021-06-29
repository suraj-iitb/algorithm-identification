#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define repc(i, b, e) for(auto i = (b); i != (e); i++)

int main(){
    int n, min, minj, s = 0;
    cin >> n;
    vector<int> v(n);
    rep(i, n){
        cin >> v.at(i);
    }
    rep(i, n){
        min = v.at(i);
        minj = i;
        repc(j, i+1, n){
            if (v.at(j) < min){
                min = v.at(j);
                minj = j;
            }
        }
        if (i != minj){
            swap(v.at(i), v.at(minj));
            s++;
        }
    }
    repc(i, v.begin(), v.end()){
        cout << (i != v.begin() ? " " : "") << *i;
    }
    cout << endl << s << endl;
    return 0;
}
