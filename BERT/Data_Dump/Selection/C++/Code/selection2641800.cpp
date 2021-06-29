#include <iostream>

using namespace std;

void selectionSort(int A[], int N) {
    int minj;
    int count = 0;

    for (int i = 0; i < N; i++) {
        minj = i;
        for (int j = i; j < N; j++) {
            if (A[minj] > A[j]) {
                minj = j;
            }
        }
        if (!(minj == i)) {
            swap(A[minj], A[i]);
            count++;
        }

    }


    for (int i = 0; i < N; i++) {
        if (i) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl << count << endl;

}

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    selectionSort(A, N);
}
