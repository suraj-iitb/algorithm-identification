#include <stdio.h>
typedef long long ll;
#define rep(i,n) for(ll i=0; i<(ll)(n); i++)

int n, k[105], v[105][105], d[105] = {0}, f[105];
int dfs(int num, int cnt){
    cnt++;
    d[num] = cnt;
    for(int i = 0; i < k[num]; i++){
        if(d[v[num][i]] == 0) cnt = dfs(v[num][i], cnt);
    }
    cnt++;
    f[num] = cnt;
    return cnt;
}

int main(){
    scanf("%d", &n);
    rep(i, n) {
        int dummy;
        scanf("%d%d", &dummy, &k[i]);
        rep(j, k[i]){
            scanf("%d", &v[i][j]);
            v[i][j]--;
        }
    }
    
    int tmp = 0;
    rep(i, n){
        if(d[i] == 0) tmp = dfs(i, tmp);
    }
    rep(i, n){
        printf("%lld %d %d\n", i+1, d[i], f[i]);
    }
}
