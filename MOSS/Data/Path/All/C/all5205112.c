
#include <bits/stdc++.h>
 
typedef long long ll;
 
using namespace std;
 
//const int MAX=INT_MAX;
 
const ll MAX=1000000000000;
 
const int mod = 1000000007;
//const int mod = 998244353;
 
//const ll A=100000000000;
const ll INF=100000000000;


int main(){
    int V,E;
    cin>>V>>E;
    
    vector<vector<ll> > dist(V,vector<ll>(V,INF));
    
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            if(i==j){
                dist[i][j]=0;
            }
        }
    }
    
    ll s,t,d;
    
    for(int i=0;i<E;i++){
        cin>>s>>t>>d;
        dist[s][t]=d;
    }
    for(int k=0;k<V;k++){
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    
    bool flag=false;
    
    for(int i=0;i<V;i++){
            if(dist[i][i]<0){
                flag=true;
                break;
            }
    }
   if(flag){
        cout<<"NEGATIVE CYCLE"<<endl;
    }else{
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(dist[i][j]>=INF/2){
                    cout<<"INF";
                    if(j!=V-1){
                        cout<<" ";
                    }
                }else{
                    cout<<dist[i][j];
                    if(j!=V-1){
                        cout<<" ";
                    }
                }
            }
            cout<<endl;
        }
    }

        
}
