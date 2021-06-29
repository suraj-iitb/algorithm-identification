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

    ll count = 0;
    for(ll i = 0; i < n; ++i){
        ll minj = i;
        for(ll j = i + 1; j < n; ++j){
            if(a.at(j) < a.at(minj)){
                minj = j;
            }
        }
        if(minj != i){
            swap(a.at(i), a.at(minj));
            count++;
        }
    }

    print_vector(a);
    cout << count << endl;
    return 0;
}

