#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int bubbleSort(vector<int>& A);

int main()
{
    int N, count;
    cin >> N;
    vector<int> A(N);
    REP(i, N) cin >> A[i];
    count = bubbleSort(A);
    for(int i = 0; i < A.size(); i++)
    {
        if(i != 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;
    return 0;
}

int bubbleSort(vector<int>& A)
{
    bool flag = true;           // 逆の隣接要素が存在する
    int swapCnt = 0;            // 反転数
    for(int i = 0; flag; i++)   // i: 未ソート部分の先頭インデックス
    {
        flag = false;
        // 配列末尾から、未ソート部分の先頭インデックスまでループ
        // 未ソート部分の最小値を配列の先頭方向に移動させる
        for(int j = A.size() - 1; j > i; j--)
        {
            // 小さい値を移動させる
            if(A[j] < A[j - 1])
            {
                swap(A[j], A[j - 1]); 
                flag = true;
                swapCnt++;
            }
        }
    }
    return swapCnt;
}
