#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll INF=1e18;
    ll n,m;
    cin>>n>>m;
    ll dis[n][n];
    ll a,b,c;
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if(i==j){
    			dis[i][j]=0;
    		}else{
    			dis[i][j]=INF;
    		}
    	}
    }
    for(int i=0;i<m;i++){
    	cin>>a>>b>>c;
    	dis[a][b]=c;
    }
    for(int k=0;k<n;k++){
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    		}
    	}
    }
    bool maki=true;
    for(int i=0;i<n;i++){
    	if(dis[i][i]<0)maki=false;
    }
    if(maki){
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
    			if(j)cout <<" ";
    			if(dis[i][j]>INF/2){
    				cout <<"INF";
    			}else{
    				cout << dis[i][j];
    			}
    		}
    		cout <<endl;
    	}
    }else{
    	cout << "NEGATIVE CYCLE" <<endl;
    }
    return 0;
}

