#include<stdio.h>
int main(void){
    int N,m,count,j,x,flag;
    scanf("%d\n",&N);
    m=N-1;
    int a[m];
    scanf("%d",&a[0]);
    for(N=1;N<=m;N++){
        scanf(" %d",&a[N]);
    }
    flag=1;
    count=0;
    while(flag==1){
        flag=0;
        for(j=N-1;j>0;j--){
            if(a[j] < a[j-1]){
                x=a[j];
                a[j]=a[j-1];
                a[j-1]=x;
                flag=1;
                count++;
            }
        }
    }
    printf("%d",a[0]);
    for(N=1;N<=m;N++){
        printf(" %d",a[N]);
    }
    printf("\n%d\n",count);
    return 0;
}
