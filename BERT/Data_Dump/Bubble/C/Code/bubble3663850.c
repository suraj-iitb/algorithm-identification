#include <stdio.h>
int main(){
    int n,i,j,swapCount=0;
    scanf("%d", &n);
    int a[n];
    for(i=0;i<n;i++) scanf("%d", &a[i]);
    for(i=0;i<n;i++){
        for(j=n-1;j>i;j--){
            if(a[j]<a[j-1]){
                a[j]^=a[j-1];
                a[j-1]^=a[j];
                a[j]^=a[j-1];
                swapCount++;
            }
        }
    }
    for(i=0;i<n-1;i++) printf("%d ",a[i]);
    printf("%d\n", a[i]);
    printf("%d\n", swapCount);
}
