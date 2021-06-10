#include <bits/stdc++.h>
using namespace std;

#define INF ((1<<30)-1)  //int32_t
#define MOD 1000000007
#define MOD2  

#define all(a)  (a).begin(),(a).end()

#define mkp make_pair
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

struct cedge{
    int to;
    int cost;
    cedge (int t ,int c) : to(t) , cost(c) {}
};

struct graph{ // if not any edge costs 1 , do cost().  Construter : numOfVs , isDirected , has minuscost (3 overloads)

    bool directed=false;
    bool cost=false;
    bool minuscost=false;
    
    bool ZeroIndexed=false;

    bool isdistcalced = false;
    
    int nv;

    //priority_queue< cedge,vector<cedge>,greater<cedge> > edges;
    vector< vector<cedge> > g;

    vector<int> dist;
    vector<int> prev;
    vector<bool> visited;


    void setv(int n){
        dist.resize(n);
        visited.resize(n);
        prev.resize(n);

        fill(all(dist),INF);
        fill(all(visited),false);
        fill(all(prev),-1);
    }

    void reset(){
        fill(all(dist),INF);
        fill(all(visited),false);
        fill(all(prev),-1);

        isdistcalced = false;
    }

    void setcosttrue(){
        cost=true;
    }

    void set0indexed(){
        ZeroIndexed = true;
    }

    graph(int n) : nv(n),g(n){setv(n);}
    graph(int n,bool direct): nv(n),g(n) , directed(direct) {setv(n);}
    graph(int n,bool direct,bool cost) : nv(n),g(n) , directed(direct) , cost(cost) {setv(n);}

    void init(int m){
        for (int i = 0; i < m; i++)
        {
            int a,b,c;

            if(cost)cin>>a>>b>>c;
            else {
                cin>>a>>b;
                c=1;
            }

            if(!ZeroIndexed){--a;--b;}

            cedge e(b,c);
            cedge re(a,c);

            g[a].push_back(e);
            if(!directed)g[b].push_back(re);
        }
    }

    void bfs(){
        queue<int> que;
        que.push(1);

        while(que.size()){
            int cur=que.front();
            visited[cur]=true;
            que.pop();

            for (int j = 0; j < g[cur].size(); j++){

                cedge e=g[cur][j];
                int nex = e.to;

                if(visited[nex]==true)continue;
                que.push(nex);

            }
            

        }
    }

    void dijkstra(int s){
        if(!ZeroIndexed)--s;
        dist[s]=0;

        priority_queue < pii,vector<pii>,greater<pii> > que;
        que.push(pii(0,s));

        while(!que.empty()){
            pii p = que.top();
            int v = p.second;
            que.pop();

            if(dist[v] < p.first)continue;

            for (int i = 0; i < g[v].size(); i++){
                cedge e = g[v][i];

                //cout << dist[e.to]<<endl;
                if(dist[e.to] > dist[v] + e.cost){

                    //cout <<"distance to "<<e.to+1<< " = "<<dist[e.to]<< " > " <<dist[v] + e.cost<< '\n';

                    dist[e.to] = dist[v] + e.cost;  //cout << "cost update!" << endl;
                    prev[e.to] = v;
                    que.push(pii((dist[e.to]),(e.to)));  //cout << "pushed!" << endl;
                }
            }
        }
    }

    void bellmanford(int s){
        --s;
        dist[s]=0;

        bool update = true;

        while(update){
            update=false;

            for (int i = 0; i < nv; i++){
                for (int j = 0; j < g[i].size(); j++){
                    cedge e = g[i][j];
                    int v = e.to;
                    
                    //cout <<i+1<<" -> "<<v+1<<" costs "<<e.cost<< endl; 
                    //cout << "v=" << v+1 << endl; 

                    if((dist[i] != INF) && (dist[v] > dist[i] + e.cost)){

                        //cout <<"distance to "<<v+1<< " = "<<dist[v]<< " > " <<dist[i] + e.cost<< '\n';

                        dist[v] = dist[i] + e.cost; cout << "cost update!" << endl;
                        prev[v] = i;
                        update = true;
                    }
                }
            }
        }
    }

    void ecmp(){
        
    }

    void prim(){

    }


    vector<int> getpath(int t){  // returns vector-type shortest path to t(1-indexed).
        if(!ZeroIndexed)--t;

        vector<int> path;
        
        for(; t!=-1;t = prev[t])path.push_back(t+1);
        reverse(all(path));

        return path;
    }


    
    void showpath(int t){
        vector<int> path = getpath(t);

        for(int i = 0;i < path.size();++i){
            cout <<"-"<< path[i] <<" - ";
        }
        cout << endl;
    }
    


    void showdist(){
        int s;
        int maxdist=0;
        for (int i = 0; i < dist.size(); i++)
        {

            if(dist[i] == INF)cout << "dist to "<<i+1<< "is TBD"<<endl;
            else {
                cout << "dist to "<<i+1<< "=" <<dist[i]<<endl;
                maxdist = max(maxdist,dist[i]);
            }

            if(dist[i] == 0){
                cout << "#this is s" <<endl;
                s = i+1;
            }
        }

        cout << "s was" << s <<endl << "maxdist is" <<maxdist<<endl;; 
    }

};

int main(){
    bool flag=true;
    ll ans=0,sum=0;
    
    int v,e,r;
    cin >>v>>e>>r;
    
    graph g(v,true,true);
    g.set0indexed();
    g.init(e);
    g.dijkstra(r);

    for (int i = 0; i < v; i++){

        if(g.dist[i] == INF)cout << "INF" << endl;
        else cout << g.dist[i] << endl;

    }

    //cout <<fixed<<setprecision(16)<< << endl;
    //cout << ans << endl;

    //if(flag)cout << "Yes" <<endl;
    //else cout << "No" <<endl;
    
    return 0;
}

