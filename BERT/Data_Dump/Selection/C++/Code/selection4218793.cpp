#include <iostream>

using namespace std;

int A[100];

int SelectionSort(int a[], int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        int selector = i;
        for (int j = i; j < n; ++j) {
            if (A[selector] > A[j])selector = j;
        }
        if (selector != i) {
            count++;
            swap(A[i], A[selector]);
        }
    }
    return count;
}

void outputArray(int a[], int n) {
    cout << a[0];
    for (int i = 1; i < n; ++i) {
        cout << ' ' << a[i];
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> A[i];
    int count = SelectionSort(A, n);
    outputArray(A, n);
    cout << count << endl;
    return 0;
}

