#include <stdio.h>

int main(){
    int i,j,k,A[100];
    scanf("%d", &k);
    for(i = 0; i < k; i++){
        scanf("%d", &A[i]);
    }
    for(j = 0; j < k-1; j++){
        printf("%d ", A[j]);
    }
    printf("%d", A[j]);
    printf("\n");
    for(i = 1; i < k; i++){
        int num;
        num = A[i];
        j = i-1;
        while(j >= 0 && A[j] > num){
            A[j+1] = A[j];
            A[j] = num;
            j--;
        }
        for(j = 0; j < k-1; j++){
            printf("%d ", A[j]);
        }
        printf("%d", A[j]);
        printf("\n");
    }
    return 0;
}
