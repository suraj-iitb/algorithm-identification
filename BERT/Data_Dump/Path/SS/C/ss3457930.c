#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
const ll mod = 1e9 + 7;
typedef pair<int,int>           PI;
typedef pair<ll,ll>             PL;
typedef vector<PI>               vip; 
typedef vector<int>             vi;
typedef vector<vi>              vvi;

const ll INF = 1e9;
struct edge{
    int to;
    int cost;
};





int main (){
    int v,e,r;
    cin >> v >> e >> r;
    vector<vector<edge> > grap(v, vector<edge>());
    vector<ll> dist(v,INF);

    REP(i,e){
        int a,b,c;
        cin >> a >> b >> c;
        grap.at(a).push_back({b,c});
    }
    dist.at(r) = 0;
    priority_queue<PI, vector<PI>, greater<PI> > que;
    que.push(PI(0,r));
    while(!que.empty()){
        PI p = que.top();
        que.pop();
        int m = p.second;
        if(dist.at(m) < p.first) continue;

        for(int i = 0; i < grap.at(m).size(); i++){

            edge e = grap.at(m).at(i);

            if(dist.at(e.to) > dist.at(m) + e.cost){

                dist.at(e.to) = dist.at(m) + e.cost;
                que.push(PI(dist.at(e.to), e.to));
            }
        }
    }

    for(int i = 0; i < v; i++){
        if(dist.at(i) == INF) cout << "INF" << endl;
        else cout << dist.at(i) << endl;
    }





    return 0;
}
