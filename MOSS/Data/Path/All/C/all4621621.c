#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;


int main(){
    int v, e;
    cin >> v >> e;
    ll dp[v+1][v+1];
    for(int i = 0; i <= v; i++){
        for(int j = 0; j <= v; j++){
            if(i == j){
                dp[i][j] = 0;
            } else {
                dp[i][j] = INF;
            }
        }
    }

    for(int i = 0; i < e; i++){
        int s,t,d;
        cin >> s >> t >> d;
        dp[s][t] = d;
    }


    for(int k = 0; k < v; k++){
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[k][j]);
            }
        }
    }

    bool negative = false;

    for(int i = 0; i < v; i++){
        if(dp[i][i] < 0){
            negative = true;
            break;
        }
    }

    if(negative){
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for(int i = 0; i < v; i++){
            for(int j = 0; j < v; j++){
                if(j != 0) cout << " ";
                if(dp[i][j] > 20000000000){
                    cout << "INF";
                } else {
                    cout << dp[i][j];
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}
