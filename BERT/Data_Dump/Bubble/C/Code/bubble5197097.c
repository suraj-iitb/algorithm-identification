#include <stdio.h>

int main(){
    // n input
    int n;
    scanf("%d", &n);

    // Array Input
    int A[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    /*
        Output must return the number of steps and the sorted array
    */

    // Bubble Sort
    int count = 0;
    for (int i = 0; i < n; i++){
        for(int j = n-1; j > i; j--){
            if(A[j] < A[j - 1]){
                count++;
                int temp = A[j];
                A[j] = A[j-1];
                A[j-1] = temp;
            }
        }
    }
    
    // Print Array
    printf("%d", A[0]);
    for(int i = 1; i < n; i++)
        printf(" %d", A[i]);
    
    // Print count
    printf("\n%d\n", count);
    return 0;
}
