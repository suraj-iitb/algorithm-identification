#include <iostream>
#define MAXN 100
using namespace std;

void printA(int *A, int n) {
    for (int i=0; i<n; i++) {
        cout << A[i];
        if (i == n-1) {
            cout << endl;
        } else {
            cout << " ";
        }
    }
}

void insertionSort(int *A, int n) {
    for (int i=1; i<n; i++) {
        printA(A, n);
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
}

int main() {
    // input
    int n;
    cin >> n;
    
    int A[MAXN];
    for (int i=0; i<n; i++) {
        cin >> A[i];
    }

    // solve and output
    insertionSort(A, n);
    printA(A, n);
}
