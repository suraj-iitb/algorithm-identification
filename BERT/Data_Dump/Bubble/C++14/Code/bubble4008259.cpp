#include <iostream>
using namespace std;

void trace(int A[], int N) {
    for (int i = 0; i < N; i++) {
        if (i > 0) { cout << " "; }
        cout << A[i];
    }
    cout << endl;
}

int bubbleSort(int A[], int N) {
    int count = 0;

    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = N - 1; j >= 1; j--) {
            if (A[j] < A[j - 1]) {
                int tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;

                flag = true;
                count++;
            }
        }
    }

    trace(A, N);
    return count;
}

int main() {
    int N;
    int A[100];

    cin >> N;
    for (int i = 0; i < N; i++) { cin >> A[i]; }

    int count = bubbleSort(A, N);
    cout << count << endl;

    return 0;
}
