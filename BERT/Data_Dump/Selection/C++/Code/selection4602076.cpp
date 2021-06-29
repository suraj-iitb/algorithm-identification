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

void selectionSort(int *A, int N) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[minj])
                minj = j;
        }
        if (i != minj) {
            int tmp;
            tmp = A[i];
            A[i] = A[minj];
            A[minj] = tmp;
            count++;
        }
    }
    print(A, N);
    cout << count << endl;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    rep(i, N) {
        cin >> A[i];
    }
    selectionSort(A, N);
}
