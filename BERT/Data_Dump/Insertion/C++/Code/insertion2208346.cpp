#include <iostream>
#include <cstdio>

using namespace std;

void insertionSort(int *, int);
void printArray(int *, int);

int main(int argc, char const* argv[]) {
    int n;
    cin >> n;
    int A[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    printArray(A, n);
    insertionSort(A, n);
    return 0;
}

void insertionSort(int *A, int n) {
    for (int i = 1; i < n; i++) {
        int tmp = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > tmp) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = tmp;
        printArray(A, n);
    }
}

void printArray(int *A, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", A[i]);
    }
    printf("%d\n", A[n-1]);
}
