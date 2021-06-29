#include <stdio.h>

int main(void){
    int n,i,j,count=0,k;
    int a[100];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]){
                k=a[j];
                a[j]=a[j+1];
                a[j+1]=k;
                count++;
            }
        }
    }
    for(i=0;i<n;i++){
        printf("%d",a[i]);
        if(i!=n-1){
            printf(" ");
        }
    }
    printf("\n%d\n",count);
    return 0;
}
