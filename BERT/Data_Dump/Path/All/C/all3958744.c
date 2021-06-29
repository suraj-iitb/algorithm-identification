#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 40;
#define FOR(i,k,n) for(int i=(k);i<(n);++i)

int V, E;
vector<vector<ll>> d;

void floyd();

int main(){
    cin >> V >> E;
    d.resize(V);
    FOR(i,0,V){
        FOR(j,0,V){
            d[i].push_back(INF);
        }
        d[i][i] = 0;
    }
    int s,t;
    ll u;
    FOR(i,0,E){
        cin >> s >> t >> u;
        d[s][t] = u;
    }
    floyd();
    
    bool flg=true;
    FOR(i,0,V){
        if(d[i][i]<0LL){
            flg=false;
            break;
        }
    }

    if(flg){
        FOR(i,0,V){
            FOR(j,0,V){
                if(j!=0) cout << " ";
                if(d[i][j]>=INF/2){
                    cout << "INF";
                }else{
                    cout << d[i][j];
                }
            }
            cout << endl;
        }
    }else{
        cout << "NEGATIVE CYCLE" << endl;
    }
    return 0;
}

void floyd(){
    FOR(k,0,V) FOR(i,0,V) FOR(j,0,V){
        d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
    }
}

