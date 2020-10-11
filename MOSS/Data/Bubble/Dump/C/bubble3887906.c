#include<stdio.h>

int main(void){
    int n;
    int a[100];
    
    scanf("%d",&n);
    
    for(int i=0;i<n;i++){
        scanf("%d",a+i);
    }
    
    int flag=1,tmp,count=0;
    while(flag){
        flag=0;
        for(int j=n-1;j>=1;j--){
            if(a[j]<a[j-1]){
                tmp=a[j];
                a[j]=a[j-1];
                a[j-1]=tmp;
                
                flag=1;
                count++;
            }
        }
    }
    
    for(int i=0;i<n-1;i++)printf("%d ",a[i]);
    printf("%d\n%d\n",a[n-1],count);
}

