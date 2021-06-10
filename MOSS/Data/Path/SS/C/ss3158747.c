#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;

ll inf = 1LL<<60;
int main(){
    int n,m,r;
    cin >> n >> m >> r;
    vector<vector<pair<ll,int> > >g(n);
    for(int i=0;i<m;i++){
        int s,t;
        ll d;
        cin >> s >> t >> d;
        g[s].push_back(make_pair(d,t));
    }
    vector<ll>dst(n);
    for(int i=0;i<n;i++){
        dst[i] = inf;
    }
    dst[r] = 0;
    priority_queue<pair<ll,int>,vector<pair<ll,int> >,greater<pair<ll,int> > >pq;
    pq.push(make_pair(0,r));
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        if(dst[x.second]!=x.first)continue;
        for(auto y:g[x.second]){
            if(dst[y.second]>dst[x.second]+y.first){
                dst[y.second] = dst[x.second]+y.first;
                pq.push(make_pair(dst[y.second],y.second));
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dst[i]==inf){
            cout << "INF" << endl;
        }else{
            cout << dst[i] << endl;
        }
    }
    return 0;
}
