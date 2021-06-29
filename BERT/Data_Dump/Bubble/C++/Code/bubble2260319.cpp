#include <stdio.h>

#define N 100

int main(){

    int i,n,a[N],b,count=0,flag;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    flag=1;
    while(flag){
        flag=0;
        for(i=n;i>1;i--){
            if(a[i-1]<a[i-2]){
                b = a[i-2];
                a[i-2] = a[i-1];
                a[i-1] = b;
                count++;
                flag = 1;
            }
        }
    }
    for(i=0;i<n-1;i++){
        printf("%d ",a[i]);
    }
    printf("%d\n%d",a[n-1],count);
    printf("\n");

    return 0;
}
