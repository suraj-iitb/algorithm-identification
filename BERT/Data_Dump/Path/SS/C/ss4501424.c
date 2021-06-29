#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main() {
    int v, e, r;
    cin >> v >> e >> r;
    vector<vector<pair<int, int>>> G(v);
    rep(i, e) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back(make_pair(b, c));
    }
    vector<int> ans;
    rep(i, v) {
        ans.push_back(INF);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    ans[r] = 0;
    que.push(make_pair(ans[r], r));
map<int,bool> m;
    while (!que.empty()) {

        pair<int, int> now = que.top();
        m[now.second]=true;
        que.pop();
        //cout<<"now=="<<now.second<<endl;;
        for (auto next : G[now.second]) {
          if(m[next.first]) continue;
            ans[next.first] = min(ans[next.first], ans[now.second] + next.second);
           // cout<<" next.first=="<<next.first<<" ans=="<<ans[next.first]<<endl;
            que.push(make_pair(ans[next.first], next.first));
        }
    
    }
    rep(i, v) {
      if(ans[i]==INF){
        cout<<"INF"<<endl;
      }else
      {
        cout<<ans[i]<<endl;
      }}
      
    return 0;
}

