#include <iostream>

using namespace std;

const int kMaxN = 100;

int selectionSort(int *a, int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        int min_i = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_i]) {
                min_i = j;
            }
        }
        
        if (i != min_i) {
            swap(a[i], a[min_i]);
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    int A[kMaxN];
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int count = selectionSort(A, n);

    for (int i = 0; i < n; i++) {
        cout << A[i];
        if (i != n - 1) {
            cout << " ";
        }
    }

    cout << endl;
    cout << count << endl;

}


