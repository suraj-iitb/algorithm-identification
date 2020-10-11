#include <stdio.h>
int main(void){
    int n,A[100],flag=1,i,j,temp,c=0,bar=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    while(flag){
        for(j=n-1;j>0;j--){
            if(A[j]<A[j-1]){
                temp=A[j];
                A[j]=A[j-1];
                A[j-1]=temp;
                c++;
            }
        }
            bar++;
            if(bar==n+1){
                break;
            }
    }
    for(i=0;i<n-1;i++){
    printf("%d ",A[i]);
    }
    printf("%d\n%d\n",A[i],c);
    return 0;
}
