#include <iostream>
using namespace std;

int selectionSort(int A[], int n) {

    int count = 0;
    for (int i = 0; i < n; i++) {
        int minj = i;
        for (int j = i; j < n; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        if (i != minj) {
            swap(A[i], A[minj]);
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int count;
    count = selectionSort(A, n);

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
