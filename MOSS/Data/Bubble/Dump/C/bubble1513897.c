#include <stdio.h>

int main() {
    int N;
    int i;
    int flag = 1;
    int j;
    int tmp;
    int counter=0;
    
    scanf("%d",&N);
    int A[N];
    
    for(i=0; i<N; i++){
        scanf("%d",&A[i]);
    }
    
    while(flag==1){
        flag = 0;
        for(j=N-1; j>0; j--){
            if(A[j]<A[j-1]){
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
                counter++;
            }
        }
    }
    for(i=0; i<N; i++){
        printf("%d",A[i]);
        if(i<N-1) printf(" ");
    }
    printf("\n%d\n",counter);
    
    
    return 0;
}
