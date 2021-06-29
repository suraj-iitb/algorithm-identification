#include <iostream>
#include <vector>

#define rep(i, l, n) for (int i = l; i < n; i++)

using namespace std;

// selectionSort(A, N) // N個の要素を含む0-オリジンの配列A
//     for i が 0 から N-1 まで
//         minj = i
//         for j が i から N-1 まで
//             if A[j] < A[minj]
//                 minj = j
//         A[i] と A[minj] を交換

int selectionSort(int A[], int n) {
    int i, j, tmp;
    int m_j;
    int cnt = 0;
    bool flag = false;
    
    rep(i, 0, n) {
        m_j = i;
        rep(j, i, n) {
            if (A[m_j] > A[j]) {
                m_j = j;
                flag = true;
            }
        }
        if (flag) cnt++;
        tmp = A[i];
        A[i] = A[m_j];
        A[m_j] = tmp;
        flag = false;
    }

    rep(i, 0, n) { 
        if (i == n-1) printf("%d", A[i]);
        else printf("%d ", A[i]);
    }
    cout << endl;

    return cnt++;
}

int main () {
    int i, n; cin >> n;
    int A[n];
    rep(i, 0, n) cin >> A[i];
    
    printf("%d\n", selectionSort(A, n));
}
