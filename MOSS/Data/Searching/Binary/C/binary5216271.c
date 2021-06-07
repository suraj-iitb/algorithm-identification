#include <stdio.h>
#include <stdlib.h>

// 二分探索
int binary_search(int x, int s[], int n){
    int left = 0, right = n, middle;
    while(left < right){
        // 基本leftより右側、leftとrightが1差だった時のみmiddle = left
        middle = (left + right) / 2;
        if (s[middle] == x){
            return 1;
        }else if (x < s[middle]){
            right = middle;
        }else{
            left = middle + 1;
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
        if (binary_search(t[i],s,n)){
            sum++;
        }
    }
    printf("%d\n",sum);
}
