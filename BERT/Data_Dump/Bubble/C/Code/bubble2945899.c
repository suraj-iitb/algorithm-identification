#include<stdio.h>
#define N 100
int main()
{
    int A[N],j,flag=1,n,a,count=0;
    scanf("%d",&n);
    for(j=0;j<n;j++){
        scanf("%d",&A[j]);
    }

    while(flag!=0){
        flag=0;
        for(j=n-1;j>=1;j--){
            if(A[j]<A[j-1]){
                a=A[j];
                A[j]=A[j-1];
                A[j-1]=a;
                flag=1;
                count++;
            }
        }
    }
    for(j=0;j<n-1;j++){
        printf("%d ",A[j]);
    }
    printf("%d\n",A[n-1]);
    printf("%d\n",count);
    return 0;

}

