#include <iostream>
using namespace std;

void print(int A[], int N);
void InsertionSort(int A[], int N);

void print(int A[], int N) {
    for (int i = 0; i < N; i++) {
        printf("%d", A[i]);
        if (i != N-1) printf(" ");
    }
    printf("\n");
}

void InsertionSort(int A[], int N) {
    for (int i = 1; i < N; i++) {
        int v = A[i];
        int j = i - 1;
        while(0 <= j && v < A[j]) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        print(A, N);
    }
}

int main () {
    int N; cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    print(A, N);
    InsertionSort(A, N);
}
