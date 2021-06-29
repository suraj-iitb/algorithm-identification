#include<stdio.h>
void Selection(int *x,int *y){
    int v;
    v = *x;
    *x = *y;
    *y = v;
}
int main(){
    int N;
    int i,j,minj;
    int count=0;
    scanf("%d",&N);
    int A[N];
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(i=0;i<=N-1;i++){
        minj=i;
        for(j=i;j<=N-1;j++){
            if(A[j]<A[minj]){
                minj=j;
            }
        }
            if(A[i]!=A[minj]){
                Selection(&A[i],&A[minj]);
                count++;
            }
    }
    for(i=0;i<N-1;i++){
        printf("%d ",A[i]);
    }
    printf("%d\n",A[N-1]);
    printf("%d\n",count);
    return 0;
}
