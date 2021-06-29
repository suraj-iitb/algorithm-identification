#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <set>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define sz(x) int(x.size())

typedef long long ll;

using namespace std;

/*******-c++14 don't include-*******/
template<typename T>
T gcd(T a, T b){if( b == 0)return a; return gcd(b, a%b); }
template<typename T>
T lcm(T a, T b){return a*b/gcd(a,b); }
/*******---------------------*******/

static const int INTINF = (2147483647);
static const ll LLINF = (1ll<<32);
static const int MAX = 101;

long long dp[MAX][MAX];

int main(int argc, const char * argv[]) {
    // input from txt
    
    /////////
    //write//
    /////////
    
    int v, e;
    cin >> v >> e;
    //v = 頂点数, e = エッジの数
    
    rep(i, MAX){
        rep(j, MAX){
            dp[i][j] = (i==j)? 0 : LLINF;
        }
    }
    
    rep(i, e){
        int s, t, d;
        cin >> s >> t >> d;
        dp[s][t] = d;
    }
    
    rep(k, v){
        rep(i, v){
            if(dp[i][k] == LLINF)continue;
            rep(j, v){
                if(dp[k][j] == LLINF)continue;
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    
    bool negative = false;
    rep(i, v){
        if(dp[i][i] <0)negative = true;
    }
    
    if(negative){
        cout << "NEGATIVE CYCLE"<< endl;
    }
    else{
        rep(i, v){
            rep(j, v){
                if(j)cout << " ";
                if(dp[i][j] == LLINF)cout << "INF";
                else
                cout << dp[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}

