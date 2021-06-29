#include <iostream>
using namespace std;

void printArray(int A[], int N) {
    for (int i = 0; i < N-1; i++) cout << A[i] << " ";
    cout << A[N-1] << endl;
}
void insertionSort(int A[], int N) {
    printArray(A, N);
    int v, j;
    for (int i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        printArray(A, N);
    }
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];
    insertionSort(A, N);
}
