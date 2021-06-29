#include <iostream>

using namespace std;

void insertionSort(int A[], int N) {
    int v, j;

    for (int i = 0; i < N; i++) {
        if (i) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;

    for (int i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;

        }
        A[j + 1] = v;
        for (int i = 0; i < N; i++) {
            if (i) {
                cout << " ";
            }
            cout << A[i];
        }
        cout << endl;
    }


}

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    insertionSort(A, N);
}
