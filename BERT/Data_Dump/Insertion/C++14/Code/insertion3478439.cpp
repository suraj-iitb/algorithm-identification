#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define repc(i, b, e) for(auto i = (b); i != (e); i++)

int main(){
    int n, t;
    vector<int> v;
    cin >> n;
    rep(i, n){
        cin >> t;
        v.push_back(t);
    }
    rep(i, n){
        rep(j, i){
            if(v.at(i) <= v.at(j)){
                v.insert(v.begin()+j, v.at(i));
                v.erase(v.begin()+i+1);
            }
        }
        repc(j, v.begin(), v.end()){
            cout << (j == v.begin() ? "" : " ") << *j;
        }
        cout << endl;
    }
    return 0;
}
