#include <iostream>
using namespace std;

int main() {
    // input
    int N;
    cin >> N;

    int A[N];
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // solve
    for (int i = 0; i <= N - 1; ++i) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        // output
        for (int i = 0; i < N - 1; ++i) {
            cout << A[i] << " ";
        }
        cout << A[N - 1] << endl;
    }

    return 0;
}
