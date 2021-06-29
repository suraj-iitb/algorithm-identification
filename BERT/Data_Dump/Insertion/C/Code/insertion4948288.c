#include<stdlib.h>
#include<stdio.h>

#define iter(i,n) for(i=0;i<n;i++)

int main(void){
    int n,i,k,v,j;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(k=0;k<n;k++){
        if(k>0){
            printf(" ");
        }
        printf("%d",a[k]);
        }
        printf("\n");
    for(i=1;i<n;i++){
        v=a[i];
        j=i-1;
        while((j>=0)&&(a[j]>v)){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        for(k=0;k<n;k++){
        if(k>0){
            printf(" ");
        }
        printf("%d",a[k]);
    }
    printf("\n");
    }
    return 0;
}
