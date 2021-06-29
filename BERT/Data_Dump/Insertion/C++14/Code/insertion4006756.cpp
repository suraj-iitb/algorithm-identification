#include <iostream>
using namespace std;

void printArray(int A[], size_t N) {
    for (int i = 0; i < N - 1; i++) {
        cout << A[i] << " ";
    }
    cout << A[N - 1] << endl;
}

int main() {
    int N;
    cin >> N;

    int A[100];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= N - 1; i++) {
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

    return 0;
}
