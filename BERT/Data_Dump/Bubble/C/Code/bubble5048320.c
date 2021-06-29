#include<stdio.h>
int main(){
    int i,j,N,count=0,key,flag=1;
    scanf("%d",&N);
    int A[N];
    for(i=0;i<N;i++) scanf("%d",&A[i]);
    
    while(flag){
        flag=0;
        for(j=N-1;j>=1;j--){
            if(A[j]<A[j-1]){
                key=A[j];
                A[j]=A[j-1];
                A[j-1]=key;
                flag=1;
                count++;
            }
        }
    }
    
    for(i=0;i<N;i++){
            if(i==N-1) printf("%d\n",A[i]);
            else printf("%d ",A[i]);
    }
    printf("%d\n",count);
    return 0;
}
