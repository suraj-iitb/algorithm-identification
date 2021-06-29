#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

static const int MAX=100;
static const long long INF=(1LL<<32);

int n;
long long d[MAX][MAX];

void wf(){
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      if(d[i][k]==INF) continue;
      for(int j=0;j<n;j++){
        if(d[k][j]==INF) continue;
        d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
}

int main(){
  int e,u,v,c;
  cin>>n>>e;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j) d[i][j]=0;
      else d[i][j]=INF;
    }
  }

  for(int i=0;i<e;i++){
    cin>>u>>v>>c;
    d[u][v]=c;
  }

wf();

  bool negative=false;
  for(int i=0;i<n;i++) if(d[i][i]<0) negative=true;

  if(negative){
    cout<<"NEGATIVE CYCLE"<<endl;
  }
  else{
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
       if(j) cout<<" ";
       if(d[i][j]==INF) cout<<"INF";
       else cout<<d[i][j];
      }
      cout<<endl;
    }
  }

  return 0;
}
