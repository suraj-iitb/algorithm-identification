#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;
static const int max_n = 10000;
static const int INF = 1e8;
const long mod =1e9 + 7;
static long long x,a,b,V,m,n,h=0,y,D=0,amax=1;
typedef pair<long long, long long> p;
static long long s[max_n],t[max_n],u[max_n],v[max_n],w[2*max_n],z[2*max_n];
static long long dp[max_n][max_n];
long long k = -2e9-1;
bool hantei[max_n];
long long minv;
void solve(){
    long long v;
    for(int i=1 ; i<n ; i++){
        v = s[i];
        a = i-1;
        while(v<s[a]&&a>=0){
            s[a+1] = s[a];
            a--;
        }
        s[a+1] = v;
        for(int j=0 ; j<n ; j++){
        if(j==n-1){
            printf("%lld\n", s[j]);
        }else{
        printf("%lld ", s[j]);
        }
    }   
     }
}
int main(){
    
    cin >> n;
    for(int  i=0 ; i<n ; i++){
        cin >> s[i];
    }
    for(int j=0 ; j<n ; j++){
        if(j==n-1){
            printf("%lld\n", s[j]);
        }else{
        printf("%lld ", s[j]);
        }
    }   
    solve();
    return 0;
}

