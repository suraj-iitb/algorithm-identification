// GRL_1_A
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ipair;
typedef pair<ll,ll> lpair;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v) //vectorの中身を見る
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

int inf=pow(10,9);
int max_n=pow(10,5);
struct edge{int to,cost;};
vector<int> setu(max_n,0); 
vector<vector<edge>> G(max_n);
vector<int> min_dis(max_n,inf);
vector<bool> seen(max_n,false);
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    int n,m,s;
    cin>>n>>m>>s;
    rep(i,m){
        int ss,tt,d;
        cin>>ss>>tt>>d;
        edge e;
        e.to=tt,e.cost=d;
        G[ss].emplace_back(e);
        setu[ss]++;
    }
    priority_queue<ipair,vector<ipair>,greater<ipair>> que; //1:現在地の暫定最短距離 2:現在地
    min_dis[s]=0; //スタート地点の最短距離は確定
    que.push(ipair(min_dis[s],s)); 

    while(!que.empty()){
        ipair q=que.top(); que.pop(); //暫定の最短距離集合の中で最短距離のnodeのmin_disが決定
        int now=q.second;
        if(seen[now]) continue;
        else seen[now]=true;
        for(int i=0;i<setu[now];i++){ //いま起点としてる頂点から行ける頂点を見る
            edge e=G[now][i];
            if(min_dis[e.to]>min_dis[now]+e.cost){
                min_dis[e.to]=min_dis[now]+e.cost;
                que.push(ipair(min_dis[e.to],e.to));
            }
        }
    }
    rep(i,n){
        if(min_dis[i]!=inf) cout<<min_dis[i]<<endl;
        else cout<<"INF"<<endl;
    }
    return 0;
}
