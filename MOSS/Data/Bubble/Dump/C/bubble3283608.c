#include <stdio.h>
int main(){
    int i,j;
    int A[100],N,num=0,v;
    
    scanf("%d",&N);
    for(i=0;i<N;i++) scanf("%d",&A[i]);

     for(i=0;i<N-1;i++){
        for(j=N-1;j>i;j--){
            if(A[j] < A[j-1]){
                v = A[j];
                A[j] = A[j-1];
                A[j-1] = v;
                num++;
            }
        }
    }
    
    printf("%d",A[0]);
    for(i=1;i<N;i++) printf(" %d",A[i]);
    printf("\n");
    printf("%d\n",num);
    return 0;  
}
