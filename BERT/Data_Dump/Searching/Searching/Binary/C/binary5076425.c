#include <stdio.h>

#define N 100000

int count = 0, numB, A[N], numA;

int binarySearch(int *, int *);

int main () {
    int B[N], i;

    scanf("%d",&numA);
    
    for(i = 0; i < numA; i++){
        scanf("%d",&A[i]);
    }

    scanf("%d",&numB);
    
    for(i = 0; i < numB; i++){
        scanf("%d",&B[i]);
    }

    count = binarySearch(A, B);

    printf("%d\n", count);

    return 0;
}

int binarySearch(int *A, int *B){
    int i, mid, sum = 0;
    
    for(i = 0; i < numB; i++){
        int left = 0, right = numA;

        while(left < right){
            mid = (left + right) / 2;

            if(A[mid] == B[i]){
                sum++;
                break;
            }
            else if(B[i] < A[mid]) right = mid;
            else left = mid + 1;
        }
    }
    return sum;
}
