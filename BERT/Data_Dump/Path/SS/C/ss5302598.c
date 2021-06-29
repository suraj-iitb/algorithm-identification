#include<bits/stdc++.h>

using namespace std;


#define MOD 1000000007
//#define MOD 998244353
#define INF 1000000010
#define EPS 1e-9

#define debug(x) cout<<x<<endl;
#define repi(i,x,n) for(int i=x;i<n;i++)
#define rep(i,n) repi(i,0,n)
#define lp(i,n) repi(i,0,n)
#define repn(i,n) for(int i=n;i>=0;i--)
#define int long long
#define endl "\n"
#define N 100000
#define F first
#define S second

typedef pair<int,int> PII;
typedef pair<int,string> PIS;
typedef pair<string,int> PSI;

struct Node{
  vector<PII> edges;//first=cost,second=index

  bool visit;
  int cost;
};

Node mp[N];

void dijkstra(int st,int n){
  rep(i,n){
    mp[i].visit=false;
    mp[i].cost= -1;
  }
  priority_queue<PII>  q;
  mp[st].cost=0;
  rep(i,mp[st].edges.size() ){
    q.push({-mp[st].edges[i].F,mp[st].edges[i].S});
  }
  mp[st].visit=true;
  while(!q.empty() ){
    PII p=q.top();
    q.pop();
    if(! mp[p.S].visit){
      mp[p.S].cost= -p.F;
      mp[p.S].visit=true;
      rep(i,mp[p.S].edges.size() ){
	q.push(make_pair(-mp[p.S].edges[i].F-mp[p.S].cost,mp[p.S].edges[i].S));
      }
    }
  }
}
      
    
signed main(){
  int v,e,r;
  cin>>v>>e>>r;
  rep(i,e){
    int a,b,c;
    cin>>a>>b>>c;
    mp[a].edges.push_back(make_pair(c,b));
  }
  dijkstra(r,v);
  rep(i,v){
    if(mp[i].cost==-1) cout<<"INF"<<endl;
    else cout<<mp[i].cost<<endl;
  }
  return 0;
}

