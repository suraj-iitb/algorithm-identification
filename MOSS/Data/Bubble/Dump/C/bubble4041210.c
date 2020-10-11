#include <stdio.h>

int main(){
  int i,j,k,count,N,flag;
  int A[100];
    
    scanf("%d",&N);
    count=0;
    
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    flag=1;
    while(flag){
        flag=0;
        for(j=N-1;j>=1;j--){
            if(A[j-1]>A[j]){
                k=A[j];
                A[j]=A[j-1];
                A[j-1]=k;
                count++;
                flag=1;
            }
        }
    }
    for(i=0;i<N-1;i++){
        printf("%d",A[i]);
        if(i!=N-1) printf(" ");
    }
    printf("%d\n",A[N-1]);
    printf("%d\n",count);
    
    return 0;
}
