#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,j,n,*a,t,count=0,m;
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        scanf("%d",a+i);
    }
    for(i=0;i<n;i++){
        m=i;
    for(j=i+1;j<n;j++){
        if(a[m]>a[j])
        m=j;
    }
    if(a[i]>a[m]){
    t=a[m];
    a[m]=a[i];
    a[i]=t;
    count++;
    }
    }
    for(i=0;i<n;i++){
        printf(i==n-1?"%d\n":"%d ",a[i]);
    }
    printf("%d\n",count);
    return 0;
}

