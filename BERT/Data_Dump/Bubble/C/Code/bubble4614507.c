#include<stdio.h>
#define swap(a,b)({a ^= b; b ^= a; a ^= b;})
int main(){
    int n, i, j, a[101], count;

    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    count=0;
    for(i = 0; i<n; i++){
        for(j = n-1; j>= i+1; j--){
            if(a[j] < a[j-1]){
                swap(a[j], a[j-1]);
                count++;
            }
        }
    }
    for(i=0;i<n-1;i++)printf("%d ", a[i]);printf("%d\n", a[i]);
    printf("%d\n", count);

return 0;
}

