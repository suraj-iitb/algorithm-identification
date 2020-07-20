#include <iostream>
using namespace std;

void bubbleSort(int A[], int N) {
    int flag = 1;
    int count = 0;
    
    while(flag) {
        flag = 0;
        for (int j = N-1; j > 0; j--) {
            if (A[j] < A[j-1]) {
                swap(A[j], A[j-1]);
                count++;
                flag = 1;
            }
        }
    }
    
    for (int i=0; i<N; i++) {
        if (i != 0) cout << " ";
        cout << A[i];
    }
    cout << "\n" << count << "\n";
}   
    /*
1   bubbleSort(A, N) // N 個の要素を含む 0-オリジンの配列 A
2   flag = 1 // 逆の隣接要素が存在する
3   while flag
4     flag = 0
5     for j が N-1 から 1 まで
6       if A[j] < A[j-1]
7         A[j] と A[j-1] を交換
8         flag = 1
    */
    
int main() {
    int N, A[100];
    cin >> N;
    for(int i=0; i<N; i++) cin >> A[i];
    
    bubbleSort(A, N);
    
    return 0;
}
