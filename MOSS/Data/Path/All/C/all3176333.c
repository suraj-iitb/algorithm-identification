#include <bits/stdc++.h>
//#include<iostream>
using namespace std;
#define int long long

#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
typedef pair<pint,int> P1;
typedef pair<int,pint> P2;
static const ll maxLL = (ll)1 << 62;
const ll MOD=1000000007;
const ll INF=1e18;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

int V,E;

int d[100][100];

void warshall_floyd(int n){
  rep(i,0,n)rep(j,0,n)rep(k,0,n){
    if(d[j][k]>d[j][i]+d[i][k])d[j][k]=d[j][i]+d[i][k];
  }
}


signed main(){
    cin.tie(0);
	ios::sync_with_stdio(false);
    cin>>V>>E;
    fill_n(*d,10000,INF);
for(int i=0;i<V;i++)d[i][i]=0;
    rep(j,0,E){
        int a,b,c;
        cin>>a>>b>>c;
        d[a][b]=c;
    }
    warshall_floyd(V);
    
    for(int i=0;i<V;i++){
       if(d[i][i]<0){
           cout<<"NEGATIVE CYCLE"<<endl;
           return 0;
       }
   }
   for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<(j?" ":"");
            if(d[i][j]>(1e9)*2)cout<<"INF";
            else cout<<d[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}
