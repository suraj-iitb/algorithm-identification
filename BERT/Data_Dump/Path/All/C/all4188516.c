#include<bits/stdc++.h>
using namespace std;
int main(){
  int v,e;
  cin >> v >> e;
  int s,t;
  long d;
  int i,j,k,l;
  vector<vector<long> >distance(v,vector<long>(v,1LL<<40));
  for(i=0;i<v;i++){
    distance[i][i] = 0;
  }
  for(i=0;i<e;i++){
    cin >> s >> t >> d;
    distance[s][t] = d;
  }
  for(k=0;k<v;k++){
    for(i=0;i<v;i++){
      for(j=0;j<v;j++){
        distance[i][j] = min(distance[i][j],distance[i][k]+distance[k][j]);
      }
    }
  }
  bool chk = true;
  for(i=0;i<v;i++){
    if(distance[i][i]<0)chk=false;
  }
  if(!chk){
    cout << "NEGATIVE CYCLE" << endl;
  }else{
    for(i=0;i<v;i++){
    for(j=0;j<v;j++){
      if(distance[i][j]>(1LL<<38))cout << "INF";
      else cout << distance[i][j];
      if(j!=v-1)cout << " ";
    }
    cout << endl;
  }}
}

