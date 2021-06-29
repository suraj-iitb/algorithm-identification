#include<iostream>
#include<algorithm>
using namespace std;

int bubbleSort(int A[], int N) {
    int flag = 1;
    int i = 0; // 未ソート部分列の先頭インデックス
    int swapCounts = 0; // ソート実行時の交換回数をカウント
    while (flag) {
        flag = 0;
        for (int j = N - 1; j > i;  j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                
                flag = 1;
                swapCounts++;
            }
        }
        i++;
    }
    return swapCounts;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++) cin >> A[i];
    
    int swapCounts = bubbleSort(A, N);
    
    for(int i = 0; i< N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;
    
    cout << swapCounts << endl;
    return 0;
}
