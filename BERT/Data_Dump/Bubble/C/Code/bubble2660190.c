#include <stdio.h>

int main(void){
    int i,j,n,m,count;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    count=0;
    for(i=0;i<n;i++){
        for(j=n-1;j>i;j--){
            if(a[j]<a[j-1]){
                m=a[j];
                a[j]=a[j-1];
                a[j-1]=m;
                count+=1;
            }
        }
        printf("%d",a[i]);
        if(i<n-1) printf(" ");
    }
    printf("\n%d\n",count);
    return 0;
}
