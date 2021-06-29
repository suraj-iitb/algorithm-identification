#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define repc(i, b, e) for(auto i = (b); i != (e); i++)

int main(){
    int n, s = 0;
    cin >> n;
    vector<int> v(n);
    rep(i, n){
        cin >> v.at(i);
    }
    bool flag = true;
    while(flag){
        flag = false;
        for(int i = n-1; i > 0; i--){
            if(v.at(i) < v.at(i-1)){
                swap(v.at(i), v.at(i-1));
                flag = true;
                s++;
            }
        }
    }
    repc(i, v.begin(), v.end()){
        cout << (i != v.begin() ? " " : "") << *i;
    }
    cout << endl << s << endl;
    return 0;
}
