#include<stdio.h>

int main(){
    int i,j,N,key;
    scanf("%d",&N);
    int A[N];
    for(i=0;i<N;i++) scanf("%d",&A[i]);
    for(i=0;i<N;i++){
        if(i==N-1) printf("%d\n",A[i]);
        else printf("%d ",A[i]);
    }
    for(j=1;j<=N-1;j++){
        key=A[j];
        i=j-1;
        while(i>=0&&A[i]>key){
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
        for(i=0;i<N;i++){
            if(i==N-1) printf("%d\n",A[i]);
            else printf("%d ",A[i]);
    }
    }
    return 0;
}
