#include<iostream>
#include<vector>
#include<queue>
#include<fstream>
using namespace std;
typedef pair<int,int> P;
struct edge{int from; int to; int cost;};
int V,E,r;
int a,b,c;
int u,v;
long int d[100000];
int dflag[100000];
long int inf=1<<30;
vector<edge> G[100000];
priority_queue<P,vector<P>,greater<P>> q;

int main(){
    edge e,ee;
    cin >> V >> E >> r;
    for(int i=0;i<E;i++){
        cin >> a >> b >> c;
        ee.from = a;
        ee.to = b;
        ee.cost = c;
        G[a].push_back(ee);
        G[b].push_back(ee);
    }
    //cout << G[0].size() << endl;
    fill(d,d+V,inf);
    
    q.push(P(0,r));
    d[r] = 0;
    while(!q.empty()){
        P p = q.top();q.pop();
        int v = p.second; 
        if(dflag[v] == 1){
            //cout << "hit" << endl;
            continue;
        }
        for(int i=0;i<G[v].size();i++){
            edge e = G[v][i];
            if(d[e.to] > p.first + e.cost){
                d[e.to] = p.first + e.cost;
                q.push(P(d[e.to],e.to));
                //cout << d[e.to] << " " << e.to << endl;
            }
        }
        dflag[v] = 1;
    }

    ofstream outputfile("kakomon56.text");

    for(int i=0;i<V;i++){
        if(d[i] >= inf){
            cout << "INF" << endl;
            outputfile << "INF\n"; 
            continue;
        }
        cout << d[i] << endl;
        outputfile << d[i] << endl;
    }
    outputfile.close();
    return 0;
}
