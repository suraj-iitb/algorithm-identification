#include<stdio.h>

int main(){
    
    int N;
    int i,j,k,v;
    int flag,count=0;
    
    scanf("%d",&N);
    
    int a[N];
    
    for(i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    
    flag=1;
    while(flag){
        flag=0;
        for(j=N-1;j>0;j--){
            if(a[j]<a[j-1]){
                v=a[j-1];
                a[j-1]=a[j];
                a[j]=v;
                flag=1;
                count++;
            }
        }
    }
       
    for(k=0;k<N-1;k++){
        printf("%d ",a[k]);
    }
    printf("%d\n",a[N-1]);
    
    printf("%d\n",count);
       
    return 0;
}
