#include<bits/stdc++.h>
using namespace std;
static const int INF =  100000 * 10000 + 100;
int main(){
    int V,E,r;
    cin >> V >> E >> r;
    vector<long int> cost(V,INF);
    vector<long int> s(E);
    vector<long int> t(E);
    vector<long int> d(E);
    for(int i = 0; i<E;i++){
        cin >> s[i] >> t[i] >> d[i];
    }
    cost[r] = 0;
    for(long int i = 0; i < V;i++){
        bool update = false;
        for(long int j = 0; j<E;j++){
            if(cost[s[j]]<INF&&cost[t[j]]>cost[s[j]]+d[j]){
                cost[t[j]]= cost[s[j]]+d[j];
                update = true;
            }
            
        }
        if(!update)break;
        
    }
    for(long int i = 0;i<V;i++){
        if(cost[i]<INF){
            cout << cost[i] << endl;
        }else{
            cout << "INF" << endl;
        }
    }
}
