#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
using namespace std;
const long long int INF = 1e18;
const long long int mod = 1e9+7;

typedef pair<ll, ll> pairs;
typedef vector<pairs> p;

struct edge{
    ll to, cost;
};


ll gcd(ll a,ll b){
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

ll lcm(ll a, ll b){
    return a / gcd(a, b) * b;
}

ll keta(ll N){
    int tmp{};
    while( N > 0 ){
        tmp += ( N % 10 );
        N /= 10;
    }
    N = tmp;
    return N;
}

// 回文
bool kai(string S){
    bool flag = true;
    for(ll i=0;i<S.size()/2;++i){
        if(S[i] != S[S.size()-i-1]){
            flag = false;
            break;
        }
    }
    return flag;
}
// ---------------------------------------------

int main(){
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;++i){
        if(i != 0){
            cout<<' ';
        }
        cin>>a[i];
        cout<<a[i];
    }
    cout<<endl;

    for(ll i=1;i<n;++i){
        ll j = i - 1;
        while(j >= 0 and a[j] > a[j+1]){
            swap(a[j], a[j+1]);
            j--;
        }

        for(ll k=0;k<n;++k){
            if(k != 0){
                cout<<' ';
            }
            cout<<a[k];
        }
        cout<<endl;
    }

    return 0;
}
