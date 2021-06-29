#include<stdio.h>
#define VMAX 10000
#define MAX 2000001

void countSort(int dst[], int src[], int n, int k){
    int i,j;
    int cnt[VMAX+1] = {};

    for(i = 1; i <= n; i++){
        cnt[src[i]]++;
    }
    for(j = 1; j <= VMAX; j++){
        cnt[j] = cnt[j] + cnt[j-1];
    }
    for(i = n; i > 0; i--){
        dst[cnt[src[i]]] = src[i];
        cnt[src[i]]--;
    }
}
int main(void){
    int i, n;
    int *src, *dst;

    scanf("%d", &n);
    src = malloc(sizeof(int)*n+1);
    dst = malloc(sizeof(int)*n+1);
    for(i = 1; i <= n; i++){
        scanf("%d", &src[i]);
    }
    countSort(dst, src, n, VMAX);
    for(i = 1; i <= n; i++){
        if(i > 1) printf(" ");
        printf("%d", dst[i]);
    }
    printf("\n");
    return 0;
}
