#include<stdio.h>
int main(){
    int i,j,N,count=0,key,minj;
    scanf("%d",&N);
    int A[N];
    for(i=0;i<N;i++) scanf("%d",&A[i]);
    
    for(i=0;i<=N-1;i++){
        minj=i;
        for(j=i;j<=N-1;j++){
            if(A[j]<A[minj]) minj=j;
        }
        if(i!=minj){
            key=A[i];
            A[i]=A[minj];
            A[minj]=key;
            count++;
        }
    }
    
    for(i=0;i<N;i++){
            if(i==N-1) printf("%d\n",A[i]);
            else printf("%d ",A[i]);
    }
    printf("%d\n",count);
    return 0;
}
