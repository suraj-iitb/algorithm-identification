#include<stdio.h>

int main(void){
    int n;
    int a[100];
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    
    int minj,count=0,tmp;
    for(int i=0;i<n;i++){
        minj=i;
        for(int j=i;j<n;j++){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        tmp=a[i];
        a[i]=a[minj];
        a[minj]=tmp;
        if(i!=minj)count++;
    }
    
    for(int i=0;i<n-1;i++)printf("%d ",a[i]);
    printf("%d\n%d\n",a[n-1],count);
}


