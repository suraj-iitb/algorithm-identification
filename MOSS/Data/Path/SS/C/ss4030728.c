#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define fi first
#define se second
#define mp make_pair
#define itrfor(itr,A) for(auto itr = A.begin(); itr !=A.end();itr++)
template <class T> using reversed_priority_queue = priority_queue<T, vector<T>, greater<T> >;
typedef long long llong;
char moji[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char moji2[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char moji3[10]={'0','1','2','3','4','5','6','7','8','9'};
#define Sort(a) sort(a.begin(),a.end());
#define Reverse(a) reverse(a.begin(),a.end());
#define print(a) cout << a << endl;
#define MOD llong(1e9+7)
#define MAX int(2 * 1e5 +5)
#define debug(x)  cout << #x << " = " << (x) << endl;
#define pi acos(-1.0)
#define int llong
#define INF llong(1e18 + 3)
template<class T> bool chmax(T &a,  T b) {if(a<b){a=b; return 1;} return 0;}
template<class T> bool chmin(T &a,  T b) {if(a>b){a=b; return 1;} return 0;}
bool Add(int &a,int b){a = (a + b) % MOD;}
void myprint(int* A,int A_num){
   REP(i,A_num) cout << A[i] << " ";
   cout << endl;
}


const int n_max = 100005;
int n;

struct edge{
    int to,cost;
};

vector<edge> E[n_max];
int dist[n_max];
int par[n_max];


void dijkstra(int v){
    reversed_priority_queue< pair<int,int> > Q;
    Q.push( mp(0,v) );
    REP(i,n) dist[i] = INF;
    REP(i,n) par[i] = -1;
    dist[v] = 0;
    bool used[n];
    REP(i,n) used[i] = false;
    while(Q.size()){
        int now = Q.top().se;
        Q.pop();
        if(used[now]) continue;
        used[now] = true;
        itrfor(itr,E[now]){
            if(dist[itr->to] > dist[now] + itr->cost  ){
                Q.push( mp(itr->cost + dist[now], itr->to) );
                par[itr->to] = now;
                dist[itr->to] = itr->cost + dist[now];
            } 
        }
    }

}


signed main(){
    int m,s;
    cin >> n >> m >> s;
    REP(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        E[a].push_back( edge{b,c} );
    }
    dijkstra(s);
    REP(i,n){
        if(dist[i] != INF){
            cout << dist[i] << endl;
        }
        else{
            cout << "INF" << endl;
        }
    }   
}
