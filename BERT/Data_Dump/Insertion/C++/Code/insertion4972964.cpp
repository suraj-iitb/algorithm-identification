#include<bits/stdc++.h>
using namespace std;

//using ll = long long;
//using pii = pair<int,int>;
#define rep(i,n) for(int i=0; i<(int)n; i++)
#define UNIQUE(v) v.erase(unique(v.begin(), v.end()), v.end()) //sortしてから使う
#define INF 2147483647
#define LLINF 9223372036854775807LL

int main(){
	int n; cin>>n;
	vector<int>V(n);
	rep(i,n) cin>>V[i];
	rep(i,n){
		int a = V[i];
		int j = i-1;
		while(j >= 0 && V[j] > a){
			swap(V[j+1], V[j]);
			j--;
		}
		V[j+1] = a;
		rep(i,n-1) cout << V[i] << " ";
		cout << V[n-1] << endl;
	}
}
