#include <bits/stdc++.h>
#define int long long
#define H 100005
using namespace std;

typedef pair<int,int> P;

int h;
P A[H];
 
void maxHeapify(int x){
  int l=x*2,r=x*2+1,lag;
  if(l<=h&&A[l].first>A[x].first)lag=l;
  else lag=x;
  if(r<=h&&A[r]>A[lag])lag=r;
  if(lag!=x){
    swap(A[x],A[lag]);
    maxHeapify(lag);
  }
}
 
void heapIncreaseKey(int x,P key){
  A[x]=key;
  while(x>1&&A[x/2]<A[x]){
    swap(A[x],A[x/2]);
    x=x/2;
  }
}
 
void insert(P key){
  A[++h].first=-1;
  heapIncreaseKey(h,key);
}
 
P extractMax(){
  P res=A[1];
  A[1]=A[h--];
  maxHeapify(1);
  return res;
}

int n, m, s, d[100005];
vector<P> G[100005];
const int INF = 1e15;

void dijkstra(){
  
  for(int i=0;i<n;i++) d[i] = INF;
  
  d[s] = 0;
  
  insert(P( 0, s ));
  
  while(h){
    
    P a = extractMax();
    
    int node = a.second;
    int cost = -a.first;
    
    if( cost > d[node] ) continue;
    
    for(P p : G[node] ){
      
      int nnode = p.first;
      int ncost = cost + p.second;
      
      if( d[nnode] > ncost ){
	d[nnode] = ncost;
	insert(P( -ncost, nnode ));
      }
      
    }
    
  }
  
  for(int i=0;i<n;i++){
    
    if( d[i] == INF ) cout<<"INF"<<endl;
    else cout<<d[i]<<endl;
    
  }
  
}

signed main(){
  
  cin>>n>>m>>s;
  
  for(int i=0;i<m;i++){
    int a, b, c;
    cin>>a>>b>>c;
    G[a].push_back(P(b,c));
  }
  
  dijkstra();
  
  return 0;
}

