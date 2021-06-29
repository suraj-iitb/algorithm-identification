#include <iostream>
using namespace std;

int bubbleSort(int A[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (A[j] < A[j-1]) {
                // swap
                int tmp = A[j-1];
                A[j-1] = A[j];
                A[j] = tmp;
                count++;
            }
        }
    }
    return count;
}

int main () {
    int n;
    cin >> n;
    int A[n];

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int count;
    count = bubbleSort(A, n);

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;

    cout << count << endl;

    return 0;
}
