#include <iostream>
// #include <vector>

using namespace std;

int selectionSort(int A[], const int N) {
    int c = 0;
    for (int i = 0; i < N; ++i) {
        int min = i;
        for (int j = i; j < N; ++j) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        if (i != min) {
            swap(A[i], A[min]);
            c++;
        }
    }
    return c;
}

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int c = selectionSort(a, n);
    for (int i = 0; i < n-1; ++i) {
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    cout << c << endl;

    return 0;
}
