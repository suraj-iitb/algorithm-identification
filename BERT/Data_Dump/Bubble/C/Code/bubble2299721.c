#include<stdio.h>
int main(){
    int i, n, a[100], flag=1, tmp, count=0;
    scanf("%d", &n);
    for(i=0; i<n; i++)scanf("%d", &a[i]);
    while(flag){
        flag=0;
        for(i=n-1; i>0; i--)if(a[i]<a[i-1]){
            tmp=a[i];
            a[i]=a[i-1];
            a[i-1]=tmp;
            flag=1;
            count++;
        }
    }
    for(i=0; i<n-1; i++)printf("%d ", a[i]);
    printf("%d\n%d\n", a[n-1], count);
    return 0;
}
