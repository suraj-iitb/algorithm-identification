#include<stdio.h>
int main(void){
    int N,m,i,j,x;
    scanf("%d\n",&N);
    m=N-1;
    int a[m];
    scanf("%d",&a[0]);
    for(N=1;N<=m;N++){
        scanf(" %d",&a[N]);
    }
    for(i=0;i<=m;i++){
        j=i+1;
        printf("%d",a[0]);
        for(N=1;N<=m;N++){
            printf(" %d",a[N]);
        }
        printf("\n");
        while(j>=1 && a[j-1]>a[j]){
            x=a[j-1];
            a[j-1]=a[j];
            a[j]=x;
            j--;
        }
    }
    return 0;
}
