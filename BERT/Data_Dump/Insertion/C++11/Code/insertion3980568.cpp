#include <bits/stdc++.h>
using namespace std;

// ソート対象の配列を出力
void printA(vector<int> A, int N)
{
    for(int i = 0; i < N; i++)
    {
        if(i == N-1) cout << A[i] << endl;
        else cout << A[i] << " ";
    }
}

// 挿入ソート
vector<int> insertionSort(vector<int> A, int N)
{
    for(int i = 1; i < N; i++)
    {
        int v = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > v)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        printA(A, N); // ステップごとの状態を出力
    }
    return A;
}

int main()
{
    // 入力
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    // 初期状態の配列を出力
    printA(A, N);
    // 挿入ソートを実行
    A = insertionSort(A, N);
    return 0;
}
