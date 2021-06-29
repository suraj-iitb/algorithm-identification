#include <stdio.h>

void insertionSort(int A[], int n);

int main(void){
    int n;
    int i;
    int A[100];
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    insertionSort(A, n);
    
    return 0;
}

void insertionSort(int A[], int n){
    int v;
    int j;
    for(int k = 0; k < n; k++)
        {
            if(k == n - 1) printf("%d\n", A[k]);
            else printf("%d ", A[k]);
        }
    for(int i = 1; i < n; i++){
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        for(int k = 0; k < n; k++)
        {
            if(k == n - 1) printf("%d\n", A[k]);
            else printf("%d ", A[k]);
        }
    }
}
