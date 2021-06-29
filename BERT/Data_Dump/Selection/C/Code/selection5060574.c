#include<stdio.h>

int main(){
    int N,j,i,n,cnt=0,minj;
    scanf("%d",&N);
    int A[N];
    for(j=0;j<N;j++){
        scanf("%d",&A[j]);
    }
    for(i=0;i<N;i++){
        minj = i;
        for(j=i;j<N;j++){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        if(A[minj]!=A[i]){
        n = A[i];
        A[i] = A[minj];
        A[minj] = n;
        cnt++;
        }
    }
    for(j=0;j<N-1;j++){
        printf("%d ",A[j]);
    }
    printf("%d\n",A[N-1]);
    printf("%d\n",cnt);
    return 0;
}
