#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,j,n,*a,t,count=0;
    scanf("%d",&n);
    a=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",a+i);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                count++;
            }
        }
    }
        for(i=0;i<n;i++)
        printf(i==n-1?"%d\n":"%d ",a[i]);
    printf("%d\n",count);
    free(a);
    return 0;
}

