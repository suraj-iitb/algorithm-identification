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
	bool flag = true;
	int ans = 0;
	while(flag){
		flag = false;
		for (int j=n-1; j>0; j--){
			if (V[j] < V[j-1]){
				swap(V[j], V[j-1]);
				flag = true;
				ans++;
			}
		}
	}
	cout << V[0];
	for (int i=1; i<n; i++) cout << " " << V[i];
	cout << endl << ans << endl;
}
