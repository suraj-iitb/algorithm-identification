#include<stdio.h>
int main(){
    int i, j, n, a[1000], v;
    scanf("%d", &n);
    for(i=0; i<n; i++)scanf("%d", &a[i]);
    for(i=1; i<n; i++){
        for(j=0; j<n-1; j++)printf("%d ", a[j]);
        printf("%d\n", a[n-1]);
        v=a[i];
        j=i-1;
        while(j>=0 && a[j]>v){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
    }
    for(i=0; i<n-1; i++)printf("%d ", a[i]);
    printf("%d\n", a[n-1]);
    return 0;
}