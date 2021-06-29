#include <stdio.h>
#define N 1000000
#define M 50000
int searchII(int *,int ,int ,int );
int main(){
    int n, q, S[N], T[M], i, j, c = 0;
    scanf("%d", &n);
    for (i = 0;i < n;i++) scanf("%d", S + i);
    scanf("%d", &q);
    for (i = 0;i < q;i++) scanf("%d", T + i);
    for (i = 0;i < q;i++)
        c += searchII(S, T[i], 0, n);
    printf("%d\n", c);
    return 0;
}
int searchII(int *S, int t, int min, int max){
    int mid;
    while (min < max) {
        mid = (min + max) / 2;
        if (S[mid] == t) return 1;
        t > S[mid] ? (min = mid + 1) : (max = mid);
    }
    return 0;
}
