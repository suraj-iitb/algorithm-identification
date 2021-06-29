#include <iostream>
using namespace std;

void coutArray(int* A, int n) {
    for (int i = 0; i < n; i++) {
        if(i > 0) {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
}

void insersionSort(int* A, int n) {
    for(int i = 1; i < n; i++) {
        int tmp = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > tmp) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = tmp;
        coutArray(A, n);
    }
}

int main() {
    int n;
    int A[100];

    // 入力
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    coutArray(A, n);
    insersionSort(A, n);
}

