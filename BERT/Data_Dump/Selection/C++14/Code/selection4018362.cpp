#include <iostream>
using namespace std;

int selectionSort(int A[], int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            count++;
            swap(A[i], A[minj]);
        }
    }
    return count;
}

int main() {
    int A[100], N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int count = selectionSort(A, N);

    for (int i = 0; i < N; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;

    return 0;
}
