#include <bits/stdc++.h>
using namespace std;
#define rep(i,k,n) for(int i=k;i<n;i++)
#define INF INT_MAX

int main(){
    int v,e;
    cin>>v>>e;
    vector< vector<int> > dis(v, vector<int>(v,INF));
    rep(i,0,e){
        int s,t,d;
        cin>>s>>t>>d;
        dis[s][t] = d;
    }

    rep(i,0,v){
        dis[i][i] = 0;
    }

    rep(k,0,v){
        rep(i,0,v){
            rep(j,0,v){
                if(dis[i][k]!=INF && dis[k][j]!=INF) dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
            if(k==v-1 && dis[i][i]<0){
                cout<<"NEGATIVE CYCLE"<<endl;
                return 0;
            }
        }
    }

    rep(i,0,v){
        rep(j,0,v){
            if(dis[i][j]==INF) cout<<"INF";
            else cout<<dis[i][j];
            printf("%c",(j==v-1)?'\n':' ');
        }
    }

    return 0;
}
