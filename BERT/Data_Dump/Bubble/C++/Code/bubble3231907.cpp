#include <iostream>
#define N_MIN 1
#define N_MAX 100
#define A_MIN 0
#define A_MAX 100
using namespace std;

int bubbleSort(int *A, int n, int num) {
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = n - 1; i >= 1; i--) {
            if (A[i] < A[i-1]) {
                swap(A[i], A[i-1]);
                num += 1;
                flag = true;
            }
        }
    }
    return num;
}

int main() {
    // input
    int n;
    cin >> n;

    int A[N_MAX];
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // solve
    int num = 0;
    num = bubbleSort(A, n, num);

    // output
    for (int i = 0; i < n; i++) {
        cout << A[i];
        if (i == n - 1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
    cout << num << endl;
}
