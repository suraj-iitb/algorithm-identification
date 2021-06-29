#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef long long ll;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define swap(a,b) {ll tp=a;a=b;b=tp;}
const ll MOD = 1000000007;

int my_lower_bound(int *p, int trg, int n){
    if(p[0] >= trg) return 0;
    int left = 0, right = n-1;
    while(right - left > 1){
        int mid = (right + left)/2;
        if(p[mid] < trg) left = mid;
        else right = mid;
    }
    return right;
}

int my_upper_bound(int *p, int trg, int n){
    if(p[n-1] <= trg) return n;
    int left = 0, right = n-1;
    while(right - left > 1){
        int mid = (right + left)/2;
        if(p[mid] > trg) right = mid;
        else left = mid;
    }
    return right;
}

int main(){
    int S[100007], T[50007];
    int n; scanf("%d", &n);
    rep(i,n) scanf("%d", S+i);
    int q; scanf("%d", &q);
    rep(i,q) scanf("%d", T+i);

    int ans = 0;
    rep(i,q){
        if(my_upper_bound(S, T[i], n) - my_lower_bound(S, T[i], n)) ans++;
    }
    
    printf("%d\n", ans);
    return 0;
}
