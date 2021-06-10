#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <map>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <cstddef>
#include <cctype>
#include <iomanip>
#include <iostream>
#include <tuple>
#include <utility>
#include <math.h>
#include <stack>
#include <queue>

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


const long long mod = 1e9+7;

void chmod(long long &M){
    if(M >= mod) M %= mod;
    else if(M < 0){
        M += (abs(M)/mod + 1)*mod;
        M %= mod;
    }
}

long long modpow(long long x, long long n){
    if(n==0) return 1;
    long long res=modpow(x, n/2);

    if(n%2==0) return res*res%mod;
    else return res*res%mod*x%mod;
}

int getl(int i, int N) { return i==0? N-1:i-1; };
int getr(int i, int N) { return i==N-1? 0:i+1; };

/* <-------------------------------------------------------------------------> */
/* <-------------------------------------------------------------------------> */
/* <-------------------------------------------------------------------------> */

const int inf = 2e9;

int main() {
    int V, E; std::cin >> V >> E;
    std::vector<std::vector<int>> dist(V, std::vector<int>(V, inf));

    for(int i = 0; i < E; ++i) {
        int s, t, d; std::cin >> s >> t >> d;
        dist[s][t] = d;
    }
    for(int i = 0; i < V; ++i) {
        dist[i][i] = 0;
    }

    for(int k = 0; k < V; ++k) {
        for(int i = 0; i < V; ++i) {
            if(dist[i][k] == inf) continue;
            for(int j = 0; j < V; ++j) {
                if(dist[k][j] == inf) continue;
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    bool negative = false;
    for(int i = 0; i < V; ++i) if(dist[i][i] < 0) negative = true;

    if(negative) {
        printf("NEGATIVE CYCLE\n");
    }
    else {
        for(int i = 0; i < V; ++i) {
            for(int j = 0; j < V; ++j) {
                if(j) printf(" ");
                if(dist[i][j] == inf) printf("INF");
                else printf("%d", dist[i][j]);
            }
            printf("\n");
        }
    }
}

