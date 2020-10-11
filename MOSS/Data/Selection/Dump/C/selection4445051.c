#include<stdio.h>
int main(void){
    int N,m,i,j,minj,count,x;
    scanf("%d",&N);
    m=N-1;
    int a[m];
    scanf("%d",&a[0]);
    for(N=1;N<=m;N++){
        scanf(" %d",&a[N]);
    }
    count=0;
    for(i=0;i<N-1;i++){
        minj=i;
        for(j=i;j<=N-1;j++){
            if(a[j]<a[minj]){
                minj=j;
            }
        }
        j=i;
        x=a[j];
        a[j]=a[minj];
        a[minj]=x;
        if(minj!=i){
            count++;
        }
    }
    printf("%d",a[0]);
    for(N=1;N<=m;N++){
        printf(" %d",a[N]);
    }
    printf("\n%d\n",count);
    return 0;
}
