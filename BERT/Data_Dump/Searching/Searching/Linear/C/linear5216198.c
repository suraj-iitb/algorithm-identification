#include <stdio.h>
#include <stdlib.h>

// 線形探索
int linear_search(int x, int s[], int n){
    for (int i = 0; i < n; i++){
        if (s[i] == x){
            return 1;
        }
    }
    return 0;
}
int main(){
    int n, q, sum = 0;
    int *s, *t;
    scanf("%d",&n);
    s = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        scanf("%d",&s[i]);
    }
    scanf("%d",&q);
    t = (int *)malloc(sizeof(int) * q);
    for (int i = 0; i < q; i++){
        scanf("%d",&t[i]);
    }
    for (int i = 0; i < q; i++){
        if (linear_search(t[i],s,n)){
            sum++;
        }
    }
    printf("%d\n",sum);
}
