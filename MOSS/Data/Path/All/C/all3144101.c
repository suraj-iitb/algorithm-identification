#include <bits/stdc++.h>
#define N 105
const long long INF = (1LL<<32);
using namespace std;
long long d[N][N];
int main(){
    int n, e;
    scanf("%d %d", &n, &e);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            d[i][j] = (i == j) ? 0 : INF;
    for(int i = 0; i < e; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        d[a][b] = c;
    }

    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            if(d[i][k] == INF) continue;
            for(int j = 0; j < n; j++)
                if(d[k][j] == INF) continue;
                else d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
        }
    }

    int flag = 0;
    for(int i = 0; i < n; i++) if(d[i][i] < 0) flag = 1;
    if(flag) printf("NEGATIVE CYCLE\n");
    else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(d[i][j] == INF) printf("INF");
                else printf("%lld", d[i][j]);
                if(j == n-1) printf("\n");
                else printf(" ");
            }
        }
    }
    return 0;
}
