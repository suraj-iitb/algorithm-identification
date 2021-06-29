#include<bits/stdc++.h>
using namespace std; 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
#define length size()
#define int long long
#define ll long long
//#include <cstdint>
const int MOD = 1000000007;
const int mod = 1000000007;
const int MAX = 510000;
const int inf = 400000000000000;
class CompareDist
{
public:
    bool operator()(pair<int,int> p,pair<int,int>q){
    return p.second > q.second;
}
};
vector<int> dijkstra(vector<vector<pair<int,int> > > vec,int s){
    priority_queue<pair<int,int>,vector<pair<int,int> >,CompareDist> que;
    pair<int,int> f = make_pair(s,0);//point,cost;
    que.push(f);
    vector<int> cost(vec.size(),inf);
    while(!que.empty()){
        pair<int,int> tmp = que.top();
        que.pop();
        int p = tmp.first;
        int c = tmp.second;
        if(cost[p]>c){
        cost[p] = c;
        rep(i,vec[p].size()){
            if(cost[vec[p][i].first]<=inf){
            tmp = make_pair(vec[p][i].first,vec[p][i].second+c);
            que.push(tmp);
            }
        }
        }
    }
    return cost;
}
signed main(void){
    int v,e,s;
    cin >> v >> e >> s;
    vector< vector< pair<int,int> > > vec(v,vector< pair<int,int> >());
    rep(i,e){
        int a,b,c;
        cin >> a >> b >> c;
        pair<int,int> tmp = make_pair(b,c);
        vec[a].push_back(tmp);
        /*tmp = make_pair(a,c);
        vec[b].push_back(tmp);*/
    }
    vector<int> ans = dijkstra(vec,s);
    rep(i,ans.size()){
        if(ans[i]==inf){
            cout << "INF" << endl;
        }else{
            cout << ans[i] << endl;
        }
    }
}

