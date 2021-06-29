#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b

signed main(){
	int n; cin>>n;
	vi v(n);
	rep(i,0,n) cin>>v[i];
	vi t=v;
	sort(all(t));
	rep(i,0,n){
		int k=v[i];
		rep(j,0,i){
			if(v[i]<v[j]){
				v.erase(v.begin()+i);
				v.insert(v.begin()+j,k);
			}
		}
		rep(l,0,n){
			cout<<v[l];
			if(l!=n-1)cout<<" ";
		}
		cout<<endl;
	}
				
	return 0;
}
