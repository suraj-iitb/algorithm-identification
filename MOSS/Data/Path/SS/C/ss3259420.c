#include <iostream>
//#define int long long
//#define _DEBUG
//#include <utility>
#include <vector>
#include <string>
using namespace std;
struct edge{
    int start;
    int end;
    int cost;
};
int V, E, r, T[500007];
vector<edge> Vs;
int const infty = 2147483647;
void solve(){
    for(int t=0; t<V; t++){
        bool updated = false;
        for(int i=0; i<E; i++){
            if(T[Vs[i].start]<infty &&
                    T[Vs[i].start]+Vs[i].cost < T[Vs[i].end]){
                T[Vs[i].end] = T[Vs[i].start]+Vs[i].cost;
                updated = true;
            }
        }
        if(!updated) break;
    }
}
bool get(){
    if(cin >> V >> E >> r && V>0){
        for(int i=0; i<V; i++){
            T[i] = infty;
        }
        T[r] = 0;
        Vs.clear();
        for(int i=0; i<E; i++){
            edge v;
            cin >> v.start >> v.end >> v.cost;
            Vs.push_back(v);
        }
        return true;
    } else return false;
}

signed main(){
    while(get()){
#ifdef _DEBUG
        for(int i=0; i<V; i++){
            cout <<Vs[i].start<<","<<Vs[i].end<<","<<Vs[i].cost<<endl;
        }
#endif
        solve();
        for(int i=0; i<V; i++){
            cout << (T[i]==infty? "INF": to_string(T[i])) << endl;
        }
    }
}
