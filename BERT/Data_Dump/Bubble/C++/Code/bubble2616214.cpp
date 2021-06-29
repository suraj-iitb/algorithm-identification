#include <iostream>
// #include <vector>

using namespace std;

int bubbleSort(int A[], const int N) {
    // 1 for i = 0 to A.length-1
    // 2     for j = A.length-1 downto i+1
    // 3         if A[j] < A[j-1]
    // 4             swap A[j] and A[j-1]
    int c = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = N-1; j > i; --j) {
            if (A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                c++;
            }
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
    int c = bubbleSort(a, n);
    for (int i = 0; i < n-1; ++i) {
        cout << a[i] << " ";
    }
    cout << a[n-1] << endl;
    cout << c << endl;

    return 0;
}
