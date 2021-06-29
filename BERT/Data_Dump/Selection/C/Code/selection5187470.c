#include <stdio.h>

void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int selectionSort(int A[], int n){
    int i,j,k;
    int numswap=0;
    for (i=0; i<n-1; i++){
        j=i+1;
        k=i;
        for(j;j<n;j++){
            if (A[j]<A[k]){
                k=j;
            }
        }
        if( i!=k){
            swap(&A[i], &A[k]);
            numswap+=1;
        }
    }
    return numswap;
}
int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i=0; i<n;i++){
        scanf("%d", &A[i]);
        }
    int numswap = selectionSort(A,n);
    printf("%d", A[0]);
    for (int k=1; k<n; k++){
        printf(" %d", A[k]);
    }
    printf("\n%d\n", numswap);
    return 0;
    }

