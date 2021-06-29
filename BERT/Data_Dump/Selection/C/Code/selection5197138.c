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
        Output the sorted array and number of swaps done
    */
    int count = 0;
    for(int i = 0; i < n; i++){
        int mini = i;
        for(int j = i; j < n; j++){
            if(A[j] < A[mini])
            mini = j;
       }
        if(mini != i){
            count++;
            int temp = A[mini];
            A[mini] = A[i];
            A[i] = temp;
        }
    }

    // Print Array
    printf("%d", A[0]);
    for (int i = 1; i < n; i++)
        printf(" %d", A[i]);

    // Print count
    printf("\n%d\n", count);
    return 0;
}
