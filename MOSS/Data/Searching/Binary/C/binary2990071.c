#include <stdlib.h>
#include <stdio.h>

int counter = 0;

int Bin(int arr[], int n, int k)
{
    int left = 0;
    int right = n - 1;
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (arr[mid] == k){
            counter++;
            return mid;
        }
        if (arr[mid] > k)
            right = mid - 1;
        else
            left = mid + 1;
    }
}

int main() {
    int n1, n2;
    scanf("%d", &n1);
    int A[n1];
    for(int i=0; i<n1; i++){
        scanf("%d", &A[i]);
    }

    scanf("%d", &n2);
    int B[n2];
    for(int i=0; i<n2; i++){
        scanf("%d", &B[i]);
    }

    int key;
    for(int j=0; j<n2; j++){
        key = B[j];
        Bin(A, n1, key);
    }

    printf("%d\n", counter);
}

