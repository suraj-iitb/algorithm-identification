#include <iostream>

using namespace std;

void InsSort(int A[], int N) {
    int i, j, v;
    for (i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while ( j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for (int k = 0; k < N; k++) {
            if (k > 0) cout << ' ';
            cout << A[k];
        }
        cout << endl;
    }
}

int main() {
    int N, i, j;
    int A[100];

    cin >> N;
    for (i = 0; i < N; i++) cin >> A[i];

    for (int k = 0; k < N; k++) {
        if (k > 0) cout << ' ';
            cout << A[k];        
    }
    cout << endl;

    InsSort(A, N);

    return 0;
}
