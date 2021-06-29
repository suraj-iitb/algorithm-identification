#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)


void print_vector(vector<ll>& a){
    REP(i, a.size()){
        cout << a.at(i);
        if(i + 1 < a.size()){
            cout << ' ';
        }
    }
    cout << endl;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n){
        cin >> a.at(i);
    }

    bool flag = true;
    ll count = 0;
    for(ll i = 0; flag; ++i){
        flag = false;
        for(ll j = a.size() - 1; j > i; --j){
            if(a.at(j) < a.at(j - 1)){
                swap(a.at(j), a.at(j - 1));
                count++;
                flag = true;
            }
        }
    }
    print_vector(a);
    cout << count << endl;
    return 0;
}

