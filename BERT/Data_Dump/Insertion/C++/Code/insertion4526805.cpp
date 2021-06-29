#include <vector>
#include <iostream>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
void insertionSort(vector<int> &A, int N) {
    for (int i = 1; i < N; ++i) {
        rep(i, N) {
            if (i != N - 1) cout << A[i] << " ";
            else cout << A[i] << endl;
        }
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            --j;
        }
        A[j + 1] = v;
    }
}
int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    insertionSort(A, N);
    rep(i, N) {
        if (i != N - 1) cout << A[i] << " ";
        else cout << A[i] << endl;
    }
}
