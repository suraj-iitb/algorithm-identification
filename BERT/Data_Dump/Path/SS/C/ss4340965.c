#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define int long long
#define vec(a,n) vector<int> (a)((n));
#define Vec(a,n) vector<string> (a)((n));
#define twovec(a,n,m) vector<vector<int>> a(n,vector<int>(m,0));
#define Twovec(a,n,m) vector<vector<double>> a(n,vector<double>(m,0));
#define P pair<int,int>
#define All(a) (a).begin(),(a).end()
#define Sort(a) sort(All(a));
#define Reverse(a) reverse(All(a));
#define PQ(n) priority_queue<P,vector<P>,greater<P>> (n)
#define pq(n) priority_queue<int> (n)
#define print(a) cout << (a) << endl
#define printD(a) cout << setprecision(15) << (a) << endl;
using namespace std;
int max_int = 2147483647;
int prime = 10e9+7;
void Debug(auto a);
int nibul(auto a,auto b);
int nibuu(auto a,auto b);
void input(vector<auto>& a,int n);
double PI = 3.14159265358979;
int n;

class dGrapf{
    vector<vector<P>> grapf;
    vector<int> d;
    public:
    dGrapf(int n){
        this->grapf.resize(n);
        this->d.resize(grapf.size(),max_int);
    }
    dGrapf(){
        this->grapf.resize(10e6);
        this->d.resize(grapf.size(),max_int);
    }
    void edge(int parent,int child,int weight=1){
        P p = P(child,weight);
        grapf[parent].push_back(p);
    }
    void dijkstra(int n){
        
        d[n] = 0;
        PQ(que);
        que.emplace(0,n);
        while(!que.empty()){
            P p = que.top();
            que.pop();
            int v = p.second;
            if(d[v] < p.first) continue;
            for(P e: grapf[v]){
                if(d[e.first] > d[v]+e.second){
                    d[e.first] = d[v]+e.second;
                    que.emplace(d[e.first],e.first);
                }
            }
        }
    }
    void bellmanford(int n){
        fill(d.begin(), d.end(), max_int);
        d[n] = 0;
        bool update = true;
        while(update){
            update = false;
            REP(i,grapf.size()){
                REP(j,grapf[i].size()){
                    if(d[i] != max_int && d[grapf[i][j].first] > d[i] + grapf[i][j].second){
                        d[grapf[i][j].first] = d[i] + grapf[i][j].second;
                        update = true;
                    }
                }
            }
        }
    }
    void print_AOJ(){
        REP(i,d.size()){
            if(d[i] == max_int){
                print("INF");
            }
            else{
                print(d[i]);
            }
        }
    }
    void De(){
        REP(i,grapf.size()){
            cout << "{";
            for(P p:grapf[i]){
                cout << "{" << p.first << "," << p.second << "}";
            }
            cout << "}\n";
        }
        Debug(d);
    }


};



signed main(){
    int v,e,r;
    cin >> v >> e >> r;
    dGrapf g(v);
    REP(i,e){
        int s,t,d;
        cin >> s >> t >> d;
        g.edge(s,t,d);
    }
    g.bellmanford(r);
    g.print_AOJ();

    return 0;
}

void Debug(auto a){
    cout << "{ ";
    for(auto b: a){
        cout << b << " ";
    }
    cout << "}" << endl;
}

//key以上の初めてのitr
int nibul(auto a,auto b){return lower_bound(All(a),b) - a.begin();}
//key以下の最後のitr
int nibuu(auto a,auto b){return upper_bound(All(a),b) - a.begin()-1;}

void input(vector<auto>& a,int n){
    REP(i,n){
        cin >> a[i];
    }
}

