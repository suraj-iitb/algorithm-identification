#include <bits/stdc++.h>
using namespace std;

int selectionSort(vector<int>& A) {
    int swapCnt = 0;
    // 検索範囲内の最小値を探し、入れ替えを行う
    // ループが進む度に検索範囲は狭くなっていく
    for(int i = 0; i < A.size(); i++) {
        int minj = i;       // 最小値のインデックスを保持する
        // 検索範囲内の最小値をA[i]と入れ替える
        for(int j = i; j < A.size(); j++) {
            // より小さい値のidxでminjを更新していく
            if(A[j] < A[minj]) {
                minj = j;
            }
        }
        if(A[i] != A[minj]) {
            swap(A[i], A[minj]);
            swapCnt++;
        }
    }
    return swapCnt;
}

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int swapCnt = selectionSort(A);

    for (int i = 0; i < A.size(); i++) {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << swapCnt << endl;
    return 0;
    
}
