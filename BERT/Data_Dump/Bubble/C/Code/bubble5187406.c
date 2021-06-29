#include <stdio.h>

void swap (int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int A[], int n){
    int numswap=0;
    int flag;
    for (int i=0; i<n-1; i++){
        flag = 0;
        for (int j=0; j<n-1-i; j++){
            if (A[j]>A[j+1]){
                swap(&A[j], &A[j+1]);
                numswap+=1;
                flag=1;
            }
        }
        if(flag==0){
                break;
            }
    }
    printf("%d", A[0]);
        for (int k=1; k<n; k++){
            printf(" %d", A[k]);
        }
        printf("\n%d\n", numswap);
}

int main(){
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i=0; i<n;i++){
        scanf("%d", &A[i]);
        }
    bubbleSort(A,n);
    return 0;
    }

