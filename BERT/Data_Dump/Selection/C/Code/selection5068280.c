#include<stdio.h>
#define N 100

int main(){
    int n,a[N],i,j,k,d=0,minj;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        minj=i;
        for(j=i;j<n;j++){
            if(a[j]<a[minj])minj=j;
        }
        if(i!=minj){
            k=a[i];
            a[i]=a[minj];
            a[minj]=k;
            d++;
        }
    }
    
    for(i=0;i<n-1;i++){
        printf("%d ",a[i]);
    }
    printf("%d\n%d\n",a[i],d);
    return 0;
}
