#include<bits/stdc++.h>
using namespace std;
using ll = long long;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define ALL(v) (v).begin(), (v).end()
#define p(s) cout<<(s)<<endl
#define p2(s, t) cout << (s) << " " << (t) << endl
#define br() p("")
#define pn(s) cout << (#s) << " " << (s) << endl
#define p_yes() p("Yes")
#define p_no() p("No")

const ll mod = 1e9 + 7;
const ll inf = 1e18;

template < typename T >
void vprint(T &V){
	for(auto v : V){
    	cout << v << " ";
	}
	cout << endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    // input
    ll N;
    cin >> N;
    vector<ll> A(N);
    FOR(i, 0, N){
        cin >> A.at(i);
    }

    vector<ll> C(10001);
    for(ll a : A){
        C[a]++;
    }

    vector<ll> Ans;
    FOR(i, 0, 10001){
        while(C[i]--){
            Ans.push_back(i);
        }
    }

    cout << Ans[0];
    FOR(i, 1, N){
        cout << ' ' << Ans[i];
    }
    cout << endl;
    
    return 0;
}
