#include<stdio.h>
int main(void){
    int n,i,j,k,v;
    int a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(k=0;k<n;k++){
            printf("%d",a[k]);
            if(k!=n-1){
                printf(" ");
            }else{
                printf("\n");
            }
    }
    for(i=1;i<n;i++){
        v=a[i];
        j=i-1;
        while(j>=0&&a[j]>v){
            a[j+1]=a[j];
            j--;
            a[j+1]=v;
            }
        for(k=0;k<n;k++){
            printf("%d",a[k]);
            if(k!=n-1){
                printf(" ");
            }else{
                printf("\n");
            }
        }
    }
    return 0;
}
