#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#define ll long long
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define EPS 1e-10
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rrep(i,n) for(int i=(int)(n)-1;i>=0;--i)
#define srep(i,s,t) for(int i=(int)(s);i<(int)(t);++i)
#define each(a,b) for(auto& (a): (b))
#define all(v) (v).begin(),(v).end()
#define len(v) (int)(v).size()
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define cmx(x,y) x=max(x,y)
#define cmn(x,y) x=min(x,y)
#define fi first
#define se second
#define pb push_back
#define show(x) cout<<#x<<" = "<<(x)<<endl
#define spair(p) cout<<#p<<": "<<p.fi<<" "<<p.se<<endl
#define sar(a,n) cout<<#a<<":";rep(pachico,n)cout<<" "<<a[pachico];cout<<endl
#define svec(v) cout<<#v<<":";rep(pachico,v.size())cout<<" "<<v[pachico];cout<<endl
#define svecp(v) cout<<#v<<":";each(pachico,v)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl
#define sset(s) cout<<#s<<":";each(pachico,s)cout<<" "<<pachico;cout<<endl
#define smap(m) cout<<#m<<":";each(pachico,m)cout<<" {"<<pachico.first<<":"<<pachico.second<<"}";cout<<endl

using namespace std;

typedef pair<int,int> P;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<P> vp;
typedef vector<string> vs;

const int MAX_N = 100000;

int in() {
    int n, c;
    while ((c = getchar()) < '0') if (c == EOF) return -1;
    n = c - '0';
    while ((c = getchar()) >= '0') n = n * 10 + c - '0';
    return n;
}

void out(int n) {
    int res[11], i = 0;
    do { res[i++] = n % 10, n /= 10; } while (n);
    while (i) putchar(res[--i] + '0');
    putchar('\n');
}

#define impl(x, last) x == last ? 0 : 31 - __builtin_clz(x ^ last)

struct RadixHeap{
    int last, size_;
    vector<P> bucket_[32];
    RadixHeap() : last(0), size_(0){}
    void push(int x, int val){
        size_++, bucket_[impl(x, last)].emplace_back(x, val);
    }
    P pop(bool flag = true){
        if(bucket_[0].empty()){
            int id = 1;
            while(bucket_[id].empty()) id++;
            last = min_element(bucket_[id].begin(), bucket_[id].end())->first;
            for(auto val : bucket_[id]){
                bucket_[impl(val.first, last)].push_back(val);
            }
            bucket_[id].clear();
        }
        P res = bucket_[0].back();
        if(flag) size_--, bucket_[0].pop_back();
        return res;
    }
    P top(){
        return pop(false);
    }
    bool empty(){
        return !size_;
    }
};

struct edge{
    int to, cost;
};

vector<edge> G[MAX_N];
int d[MAX_N];

int main()
{
    int n, m, s;
    n = in(), m = in(), s = in();
    rep(i,m){
        int a,b,c;
        a = in(), b = in(), c = in();
        G[a].pb((edge){b, c});
    }
    memset(d, INF, sizeof(d));
    RadixHeap que;
    d[s] = 0;
    que.push(0, s);
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(auto& e : G[v]){
            if(d[e.to] > d[v] + e.cost){
                d[e.to] = d[v] + e.cost;
                que.push(d[e.to], e.to);
            }
        }
    }
    rep(i,n){
        if(d[i] == INF){
            putchar('I'), putchar('N'), putchar('F'), putchar('\n');
        }else{
            out(d[i]);
        }
    }
    return 0;
}

