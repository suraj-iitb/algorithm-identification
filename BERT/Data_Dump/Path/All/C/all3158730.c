#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll inf = 1LL<<60;
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<ll > > dst(n,vector<ll>(n)),dst2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dst[i][j] = inf;
        }
        dst[i][i] = 0;
    }
    for(int i=0;i<m;i++){
        int s,t;
        ll d;
        cin >> s >> t >> d;
        dst[s][t] = d;
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dst[i][k]!=inf&&dst[k][j]!=inf)dst[i][j] = min(dst[i][j],dst[i][k]+dst[k][j]);
            }    
        }
    }
    dst2 = dst;
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dst[i][k]!=inf&&dst[k][j]!=inf)dst[i][j] = min(dst[i][j],dst[i][k]+dst[k][j]);
            }    
        }
    }
    bool flag = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(dst[i][j]!=dst2[i][j]){
                flag = 1;
            }
        }
    }
    if(flag){
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }else{
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dst[i][j]==inf){
                    cout << "INF"; 
                }else{
                    cout << dst[i][j];
                }
                if(j!=n-1){
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}
