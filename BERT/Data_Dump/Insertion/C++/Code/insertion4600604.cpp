#include <iostream>
#define rep(i, n) for (int i=0; i<n; i++)
#define ll long long
using namespace std;

void print(int *A, int N) {
    rep(i, N) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << "\n";
}

void insertionSort(int *A, int N) {
    for (int i = 1; i < N; i++) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        print(A, N);
    }
}

int main() {
    int N;
    cin >> N;
    int A[N];
    rep(i, N) {
        cin >> A[i];
    }
    print(A, N);
    insertionSort(A, N);
}
