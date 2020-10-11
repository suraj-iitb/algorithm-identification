#include<stdio.h>
int main(){
    int i, j, a[100], n, minj, tmp, count=0;
    scanf("%d", &n);
    for(i=0; i<n; i++)scanf("%d", &a[i]);
    for(i=0; i<n; i++){
        minj=i;
        for(j=i; j<n; j++)if(a[j]<a[minj]){
                minj=j;
        }
        if(minj!=i)count++;
        tmp=a[i];
        a[i]=a[minj];
        a[minj]=tmp;
    }
    for(i=0; i<n-1; i++)printf("%d ", a[i]);
    printf("%d\n%d\n", a[n-1], count);
    return 0;
}
