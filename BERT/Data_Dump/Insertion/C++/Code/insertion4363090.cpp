#include <iostream>
using namespace std;

void showA(int A[], int n) {
    for (int i = 0; i < n; i++) {
        if (i != 0) cout << " ";
        cout << A[i];
    }
    cout << "\n";
}

/*
1 insertionSort(A, N) // N個の要素を含む0-オリジンの配列A
2   for i が 1 から N-1 まで
3     v = A[i]
4     j = i - 1
5     while j >= 0 かつ A[j] > v
6       A[j+1] = A[j]
7       j--
8     A[j+1] = v
*/

int main() {
    int n, v, A[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> A[i];
    
    for (int i = 0; i < n; i++) {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        showA(A, n);
    }
    
    return 0;
}
