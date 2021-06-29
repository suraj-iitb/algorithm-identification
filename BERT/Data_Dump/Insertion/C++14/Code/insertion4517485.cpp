#include <iostream>
using namespace std;

void output(int N, int A[]) {
    for (int i = 0; i < N; i++) {
        if (i == N-1) {
            cout << A[N-1] << endl;
            break;
        }
        cout << A[i] << " ";
    }
}

int main() {
    int N, j, key;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    output(N, A);

    for (int i = 1; i < N; i++) {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
        output(N, A);
    }
    return 0;
}
