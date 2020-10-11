#include <stdio.h>

int main(){
    int i,j,k=0,n,flag=1,x,y;
    
    scanf("%d",&n);
    int A[n];
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    while(flag!=0){
        flag=0;
        for(i=n-1;i>=1;i--){
            if(A[i]<A[i-1]){
                x=A[i];
                y=A[i-1];
                A[i]=y;
                A[i-1]=x;
                flag=1;
                k++;
            }
        }
    }
    for(i=0;i<n;i++){
        if(i==n-1) printf("%d",A[i]);
        else printf("%d ",A[i]);
    }
    printf("\n%d\n",k);
    return 0;
}
