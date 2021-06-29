#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
#define INF 1020304050
typedef pair<int,int> P;

int main()
{
  int nv,ne,r;cin>>nv>>ne>>r;
  vector<int> s(ne);
  vector<int> t(ne);
  vector<int> d(ne);
  int i;
  rep(i,ne)cin>>s[i]>>t[i]>>d[i];
  vector<vector<P>> g(nv);
  rep(i,ne)
  {
    g[s[i]].emplace_back(make_pair(t[i],d[i]));
  }
  vector<int> ans(nv,INF);
  ans[r]=0;
  priority_queue<P, vector<P>, greater<P>> q;
  q.push(make_pair(0,r));
  while(!q.empty())
  {
    P nowp=q.top();
    q.pop();
    int v=nowp.second;
    if(ans[v]<nowp.first)continue;
    rep(i,g[v].size())
    {
      P nowe=g[v][i];
      if(ans[nowe.first]>ans[v]+nowe.second)
      {
        ans[nowe.first]=ans[v]+nowe.second;
        q.push(make_pair(ans[nowe.first],nowe.first));
      }
    }
  }
  rep(i,nv)
  {
    if(ans[i]==INF)cout<<"INF"<<endl;
    else cout<<ans[i]<<endl;
  }
}


