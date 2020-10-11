#include <stdio.h>

int main(int argc, const char * argv[]) {
    int i, j;
    int temp;
    int N;
    int A[100];
    int count = 0;
    
    scanf("%d", &N);
    
    for(i=0;i<N;i++){
        scanf("%d", &A[i]);
    }
    
    for(i=0;i<N-1;i++){
        for(j=N-1;j>i;j--){
            if(A[j-1]>A[j]){
                temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
                count ++;
            }
        }
    }
    
    for(i=0;i<N;i++){
        if(i>0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n%d\n", count);
    
    return 0;
}
