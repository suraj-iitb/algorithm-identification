#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class T>
class PriorityQueue{
    vector<deque<T>>dat;
    vector<int32_t>count;
    int32_t num;
public:
    PriorityQueue():num(0){}
    void add(const T &x){
        dat.push_back({x});
        count.push_back(1);
        num++;
        while(dat.size()>1&&count[dat.size()-2]==count[dat.size()-1]){
            auto x=dat[dat.size()-2];
            auto y=dat[dat.size()-1];
            int z=count[dat.size()-1]*2;
            dat.pop_back();count.pop_back();
            dat.pop_back();count.pop_back();
            dat.push_back(deque<T>(x.size()+y.size()));
            count.push_back(z);
            merge(x.begin(),x.end(),y.begin(),y.end(),dat.back().begin());
        }
    }
    T getMin(){
        int32_t cur=0;
        while(cur<dat.size()&&dat[cur].size()==0)cur++;
        assert(cur!=dat.size());
        T res=dat[cur][0];
        for(int32_t i=cur+1;i<dat.size();i++){
            if(dat[i].size())res=min(res,dat[i][0]);
        }
        return res;
    }
    T getMax(){
        int32_t cur=0;
        while(cur<dat.size()&&dat[cur].size()==0)cur++;
        assert(cur!=dat.size());
        T res=dat[cur].back();
        for(int32_t i=cur+1;i<dat.size();i++){
            if(dat[i].size())res=max(res,dat[i].back());
        }
        return res;
    }
    void removeMin(){
        T val=getMin();
        num--;
        for(int32_t i=0;i<dat.size();i++){
            if(dat[i].size()&&dat[i][0]==val){
                dat[i].pop_front();
                return;
            }
        }
    }
    void removeMax(){
        T val=getMax();
        num--;
        for(int32_t i=0;i<dat.size();i++){
            if(dat[i].size()&&dat[i].back()==val){
                dat[i].pop_back();
                return;
            }
        }
    }
    inline int32_t size(){
        return num;
    }
};

signed main(){
    int N,M,r;
    cin>>N>>M>>r;
    vector<vector<pint>>G(N);
    rep(i,M){
        int a,b,c;
        cin>>a>>b>>c;
        G[a].pb({b,c});
    }

    vint dist(N,INT_MAX);
    dist[r]=0;
    PriorityQueue<pint>que;
    que.add({0,r});
    while(que.size()){
        auto p=que.getMin();
        que.removeMin();
        if(dist[p.se]<p.fi)continue;
        for(auto &e:G[p.se]){
            if(dist[e.fi]<=p.fi+e.se)continue;
            dist[e.fi]=p.fi+e.se;
            que.add({dist[e.fi],e.fi});
        }
    }

    rep(i,N){
        if(dist[i]==INT_MAX)puts("INF");
        else printf("%lld\n",dist[i]);
    }
    return 0;
}
