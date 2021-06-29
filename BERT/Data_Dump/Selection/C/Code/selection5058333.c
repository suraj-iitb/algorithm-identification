#include<stdio.h>
#define N 100
int main()
{
    int a[N],i,j,k,num,tmp,minj,cnt=0;
    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%d",&a[i]);
    }
    
    for(i=0;i<num-1;i++){
        minj=i;
        for(j=i;j<=num-1;j++){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        if(a[minj]!=a[i]){
        tmp=a[i];
        a[i]=a[minj];
        a[minj]=tmp;
        cnt++;
        }
    }
    
    
        for(k=0;k<num-1;k++){
            printf("%d ",a[k]);
            }
            printf("%d",a[num-1]);
            printf("\n");
            printf("%d",cnt);
            printf("\n");
            
    
    return 0;
}

