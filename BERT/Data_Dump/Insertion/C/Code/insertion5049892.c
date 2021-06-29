#include<stdio.h>
#define N 100
int main()
{
    int a[N],i,j,k,v,num;
    scanf("%d",&num);
    for(i=0;i<num;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<num-1;i++){
        printf("%d ",a[i]);
    }
    printf("%d",a[num-1]);
    printf("\n");
    for(i=1;i<=num-1;i++) {
        v=a[i];
        j=i-1;
        while((j>=0)&&(a[j]>v)){
            a[j+1]=a[j];
            j--;
            }
            a[j+1]=v;
        for(k=0;k<num-1;k++){
            printf("%d ",a[k]);
            }
            printf("%d",a[num-1]);
            printf("\n");
            }
    
    return 0;
}
