#include <iostream>
#include <vector>

#define rep(i, l, n) for (int i = l; i < n; i++)

using namespace std;

// bubbleSort(A, N) // N 個の要素を含む 0-オリジンの配列 A
//    flag = 1 // 逆の隣接要素が存在する
//    while flag
//         flag = 0
//         for j が N-1 から 1 まで
//             if A[j] < A[j-1]
//                 A[j] と A[j-1] を交換
//                 flag = 1

int bubbleSort(int A[], int n) {
    int i, tmp;
    int cnt = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = n-1; j > 0; j--) {
            if (A[j] < A[j-1]) {
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = true;
                cnt++;
            }
            //rep(i, 0, n) printf("%d ", A[i]);cout << endl;
        }
    }
    rep(i, 0, n) { 
        if (i == n-1) printf("%d", A[i]);
        else printf("%d ", A[i]);
    }
    cout << endl;
    return cnt;
}

int main () {
    int i, n; cin >> n;
    int A[n];
    rep(i, 0, n) cin >> A[i];
    
    printf("%d\n", bubbleSort(A, n));
}
