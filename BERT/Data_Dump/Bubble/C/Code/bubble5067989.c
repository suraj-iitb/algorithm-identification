#include<stdio.h>
#define N 100

int main(){
    int n,i,a[N],k,d=0,o,fg;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    o=n;
    for(;o!=1;o--){
        for(i=0;i<n-1;i++){
            fg=0;
            if(a[i]>a[i+1]){
                fg=1;
                k=a[i];
                a[i]=a[i+1];
                a[i+1]=k;
                d++;
            }
        }
        if(fg=0)break;
    }
    for(i=0;i<n-1;i++){
        printf("%d ",a[i]);
    }
    printf("%d\n%d\n",a[i],d);
    return 0;
}

