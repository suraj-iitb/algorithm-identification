#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

const ll INF = 1LL<<60;

ll d[105][105];

int main(){
	ll V,E;
	cin >> V >> E;
	
	rep(i,V){
		rep(j,V){
			if(i == j){
				d[i][j] = 0;
			}else{
				d[i][j] = INF;
			}
		}
	}
	
	rep(i,E){
		ll s,t,w;
		cin >> s >> t >> w;
		d[s][t] = w;
	}
	
	rep(k,V){
		rep(i,V){
			rep(j,V){
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	
	bool negative_cycle = false;
	
	rep(i,V){
		if(d[i][i] < 0) negative_cycle = true;
	}
	
	if(negative_cycle){
		cout <<  "NEGATIVE CYCLE" << endl;
	}else{
		rep(i,V){
			rep(j,V){
				if(j == V-1){
					if(d[i][j] >= INF/2){
						cout << "INF" << endl;
					}else{
						cout << d[i][j] << endl;
					}
				}else{
					if(d[i][j] >= INF/2){
						cout << "INF" << " ";
					}else{
						cout << d[i][j] << " ";
					}
				}
			}
		}
	}
    return 0;
}


