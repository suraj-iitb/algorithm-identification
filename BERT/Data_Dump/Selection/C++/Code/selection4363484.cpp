#include <iostream>
using namespace std;

void selectionSort(int A[], int N) {
    int count = 0;
    for (int i=0; i<N; i++) {
        int minj = i;
        for (int j=i; j<N; j++) {
            if (A[j] < A[minj]) minj = j;
        }
        if (A[i] != A[minj]) {
        swap(A[i], A[minj]);
        count++;
        }
    }
    
    for (int i=0; i<N; i++) {
        if (i != 0) cout << " ";
        cout << A[i];
    }
    
    cout << "\n" << count << "\n";
}

/*
1 selectionSort(A, N) // N個の要素を含む0-オリジンの配列A
2   for i が 0 から N-1 まで
3     minj = i
4     for j が i から N-1 まで
5       if A[j] < A[minj]
6         minj = j
7     A[i] と A[minj] を交換
*/

int main() {
    int N, A[100];
    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];
    
    selectionSort(A, N);
    
    return 0;
}
