#include <bits/stdc++.h>
using namespace std; 
#define int int64_t
#define itn int
#define fi first
#define se second
#define mod 1000000007
const int INF = (LLONG_MAX / 2);
signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);  
  int v,e,m;
  int s,t,d;
  int w[105][105]={};
  cin>>v>>e;
  for(int i=0;i<v;i++){
    for(int j=0;j<v;j++) if(i!=j) w[i][j]=INF;
  }
  for(int i=0;i<e;i++){
    cin>>s>>t>>d;
    w[s][t]=d;
  }
  for(int i=0;i<v;i++){
    for(int j=0;j<v;j++){
      for(int k=0;k<v;k++){
	w[j][k]=min(w[j][k],w[j][i]+w[i][k]);
      }
    }
  }
  bool f=true;
  for(int i=0;i<v;i++){
    if(w[i][i]<0) f=false;
  }
  if(f){
    for(int i=0;i<v;i++){
      for(int j=0;j<v;j++){
	if(w[i][j]<INF/2) cout<<w[i][j];
	else cout<<"INF";
	if(j!=v-1) cout<<" ";
      }
      cout<<"\n";
    }
  }
  else cout<<"NEGATIVE CYCLE\n";
  return 0;
}

