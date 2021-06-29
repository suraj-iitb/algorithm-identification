#include <iostream>
#include <cstdio>

using namespace std;

void bubbleSort(int *, int, int *);
void printArray(int *, int);

int main(int argc, char const* argv[]) {
    int n;
    cin >> n; 
    int A[100];
    int count;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    bubbleSort(A, n, &count);
    printArray(A, n);
    cout << count << endl;
    return 0;
}

void bubbleSort(int *A, int n, int *count) {
    int flag = 1;
    while (flag == 1) {
        flag = 0;
        for (int i = n - 1; i > 0; i--) {
            if (A[i] < A[i-1]) {
                int tmp = A[i];
                A[i] = A[i-1];
                A[i-1] = tmp;
                flag = 1;
                (*count)++;
            }
        }
    }
}

void printArray(int *A, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d ", A[i]);
    }
    printf("%d\n", A[n-1]);
}
