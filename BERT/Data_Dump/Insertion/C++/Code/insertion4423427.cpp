#include <iostream>
using namespace std;

void printArray(int A[], int N) {
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    return;
}

void insertionSort(int A[], int N) {
    for (int i = 1; i < N; i++) {
        printArray(A, N);
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
    }
    printArray(A, N);
    return;
}

int main() {
    int N, A[110];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i];
    insertionSort(A, N);
    return 0;
}
