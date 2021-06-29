#include <iostream>
using namespace std;

int selectionSort(int A[], int N) {
    int sw = 0, minj;
    for (int i = 0; i < N; i++) {
        minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) minj = j;
        }
        swap(A[i], A[minj]);
        if (i != minj) sw++;
    }
    for (int i = 0; i < N-1; i++) cout << A[i] << " ";
    cout << A[N-1] << endl;
    return sw;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for(int i = 0; i < N; i++) cin >> A[i];

    int sw = selectionSort(A, N);
    cout << sw << endl;
}
