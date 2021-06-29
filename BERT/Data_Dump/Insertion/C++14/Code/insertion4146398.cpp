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

void insertion_sort(vector<ll>& a){
    print_vector(a);
    for(ll i = 1; i < a.size(); ++i){
        const ll v = a.at(i);
        ll j;
        for(j = i - 1; j >= 0 && a.at(j) > v; --j){
            a.at(j + 1) = a.at(j);
        }
        a.at(j + 1) =  v;
        print_vector(a);
    }
}

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    REP(i, n){
        cin >> a.at(i);
    }
    insertion_sort(a);
    return 0;
}

