#include <stdio.h>
#include <stdlib.h>
int main(){
    int i,j,k,N,v,*A;

    scanf("%d",&N);
    if(!(1 <= N && N <= 100)) exit(0);

    A = (int *)malloc(sizeof(int) * N);
    if(A==NULL) exit(0);

    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
        if(!(0<=A[i] && A[i] <= 1000)) exit(0);
    }
    
    for(k=0;k<N;k++){
            if(k==N-1) printf("%d",A[k]);
            else printf("%d ",A[k]);
        }
    printf("\n");

    for(i=1;i<N;i++){
        v = A[i];
        j = i - 1;
        while(j>=0 && A[j] > v){
            A[j+1] = A[j];
            j--;
        } 
        A[j+1] = v;
        for(k=0;k<N;k++){
            if(k==N-1) printf("%d",A[k]);
            else printf("%d ",A[k]);   
        }
        printf("\n");
    }

    return 0;
}
