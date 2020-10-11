#include <stdio.h>

int main(){
    int n,i,j,minIx=0,swapCount=0,needSwap=0;
    scanf("%d", &n);
    int a[n];
    for(i=0;i<n;i++) scanf("%d", &a[i]);
    for(i=0;i<n;i++){
        minIx = i;
        for(j=i;j<n;j++){
            if(a[j]<a[minIx]){
                minIx = j;
                needSwap = 1;
            }
        }
        if(needSwap){
        a[i]^=a[minIx];
        a[minIx]^=a[i];
        a[i]^=a[minIx];
        needSwap = 0;
        swapCount++;
        }
    }
    for(i=0;i<n-1;i++) printf("%d ",a[i]);
    printf("%d\n", a[i]);
    printf("%d\n", swapCount);
}
