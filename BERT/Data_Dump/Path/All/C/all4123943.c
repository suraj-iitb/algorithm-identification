#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 10010010010

int main(){
    ll v,e;
    cin >> v >> e;
    ll a[v][v];
    
    for(ll i=0;i<v;i++){
        for(ll j=0;j<v;j++){
            if(i==j){
                a[i][j]=0;
            }else{
                a[i][j]=INF;
            }
        }
    }
    
    for(ll i=0;i<e;i++){
        ll s,t,d;
        cin >> s >> t >> d;
        a[s][t]=d;
    }
    
    for(ll k=0;k<v;k++){
        for(ll i=0;i<v;i++){
            if(a[i][k]==INF) continue;
            for(ll j=0;j<v;j++){
                if(a[k][j]==INF) continue;
                a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
            }
        }
    }
    
    for(ll i=0;i<v;i++){
        if(a[i][i]<0){
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }
    
    for(ll i=0;i<v;i++){
        for(ll j=0;j<v;j++){
            if(j!=0) cout << " ";
            if(a[i][j]==INF) cout << "INF";
            else cout << a[i][j];
        }
        cout << endl;
    }
    
    
    return 0;
}








