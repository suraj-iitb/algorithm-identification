#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);++i)
using ll=long long;
constexpr ll INF=1000000011;
constexpr ll LINF = 1001002003004005006ll;
vector<vector<ll>> dp; // グラフの距離を格納した2次元配列（隣接行列）
                      // d[u][v]は辺e=(u,v)のコスト（辺が存在しない場合はINF、ただしd[i][i]=0）
ll nex[1000][1000];  //  i から j への最短経路における i の1つ後の点　経路復元

void WF(ll N){      // nは頂点数
    // 経路復元の初期化
    rep(i,N){
        rep(j,N){
            nex[i][j]=j;
        }
    }
    rep(k,N){           // 経由する頂点
        rep(i,N){       // 開始頂点
            if(dp[i][k]==LINF){
                continue;
            }
            rep(j,N){   // 終端 
                if(dp[k][j]==LINF){
                    continue;
                }
                if(dp[i][j]>dp[i][k]+dp[k][j]){
                    dp[i][j] = min (dp[i][j],dp[i][k]+dp[k][j]);
                    nex[i][j] = nex[i][k];
                }
            }
        }
    } 
}

void way_of_WF(ll s,ll g){ //  経路復元の出力　s->gの最短経路
    ll cur;  
    for (cur = s; cur != g; cur = nex[cur][g]){
        cout << cur << " ";
    }
    cout << g << endl;
}

bool negative(ll N){  //負の閉路が存在するなら１を返す
    rep(i,N){
        if(dp[i][i]<0){
            return 1;
        }
    }
    return 0;
}

int main(){
    ll N,M,X,Y,L;
    cin >> N;
    dp = vector<vector<ll>> (N,vector<ll>(N,LINF));
    rep(i,N){
        dp[i][i]=0;
    }
    cin >> M ;
    rep(i,M){
        cin >> X >> Y >> L;
        dp[X][Y]=L;
    }

    WF(N);

    if(negative(N)){
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    
    rep(i,N){
        rep(j,N){
            if(dp[i][j]==LINF){
                cout << "INF";
            }
            else{
                cout << dp[i][j];
            }
            if(j!=N-1){
                cout << " ";
            }
        }
        cout << endl;
    }
}
