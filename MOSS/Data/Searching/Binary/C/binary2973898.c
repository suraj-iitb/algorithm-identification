#include <stdlib.h>
#include <stdio.h>

int counter = 0;

int Bin(int arr[], int size, int k)
{
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == k){
            counter++;
            return mid;
        }
        if (arr[mid] > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
}

int main(int argc, char** argv) {
    int n1, n2;
    scanf("%d", &n1);
    int arr1[n1];
    for(int i=0; i<n1; i++){
        scanf("%d", &arr1[i]);
    }

    scanf("%d", &n2);
    int arr2[n2];
    for(int i=0; i<n2; i++){
        scanf("%d", &arr2[i]);
    }

    int key;
    for(int j=0; j<n2; j++){
        key = arr2[j];
        Bin(arr1, n1, key);
    }

    printf("%d\n", counter);
}

