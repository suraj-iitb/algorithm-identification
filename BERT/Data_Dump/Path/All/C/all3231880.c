#include <iostream>

using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);++i)
#define INF 2147483600
const ll V=110;
ll d[V][V];
ll n;
void Warshall_Floyd(){
  rep(k,n){
    rep(i,n){
      rep(j,n){
        if(d[i][j]>(d[i][k]+d[k][j])){
          d[i][j]=d[i][k]+d[k][j];
        }
      }
    }
  }
}
int main(){
  ll e;cin>>n>>e;
  fill(d[0],d[101],1e18);
  ll s,t,w;
  rep(i,e){
    cin>>s>>t>>w;
    d[s][t]=w;
  }
  rep(i,n){
    d[i][i]=0;
  }
  Warshall_Floyd();
  rep(i,n){
    if(d[i][i]<0){
      cout<<"NEGATIVE CYCLE"<<endl;
      return 0;
    }
  }
  rep(i,n){
    rep(j,n){
      if(j!=n-1){
        if(d[i][j]>1e10){
          cout<<"INF"<<" ";
        }else{
          cout<<d[i][j]<<" ";
        }
      }else{
        if(d[i][j]>1e10){
          cout<<"INF";
        }else{
          cout<<d[i][j];
        }
      }
    }
    cout<<endl;
  }
  return 0;
}
