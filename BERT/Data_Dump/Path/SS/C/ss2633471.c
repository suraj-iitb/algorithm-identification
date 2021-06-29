#include<iostream>
#include<vector>
using namespace std;

int main(){
  int iv,ie,r;
  cin >> iv >> ie >> r;
  int d[100010];
  for (int i=0;i<iv;i++){
    d[i]= 1000000010;
  }
  d[r]=0;
  vector<pair<int,int> > w(ie);
  vector<int> cost(ie);
  for(int i=0;i<ie;i++){
    int s0,e0,d0;
    cin>>s0>>e0>>d0;
    w[i] = make_pair(s0,e0);
    cost[i]=d0;
  }
  for(int i=0;i<iv-1;i++){
    int k=0;
    for(int j=0;j<ie;j++){
      int s1,e1,d1;
      s1=w[j].first;
      e1=w[j].second;
      d1=cost[j];
      if(d[e1]>d[s1]+d1) k+=1;
      d[e1]=min(d[e1],d[s1]+d1);
    }
    if(k==0) break;
   }

  for(int i=0;i<iv;i++){
    if(d[i]==1000000010){
      cout<<"INF"<<endl;
    }else{
      cout<<d[i]<<endl;
    }
  }
}
