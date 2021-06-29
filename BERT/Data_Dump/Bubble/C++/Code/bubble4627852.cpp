#include <bits/stdc++.h>
#include <cmath>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int,int>;

void bubbleSort(vector<int>& A_ref, int N, int& change_cnt){ // N 個の要素を含む 0-オリジンの配列 A
    int flag = 1; // 逆の隣接要素が存在する
    while (flag){
        flag = 0;
        for (int j=N-1;j>0;j--){
            if (A_ref[j] < A_ref[j-1]){
                int tmp_Aj = A_ref[j];
                A_ref[j]=A_ref[j-1];
                A_ref[j-1]=tmp_Aj;
                change_cnt++;
                flag = 1;
            }
        }
    }
}

int main(){
    int N, change_cnt=0;
    cin >> N;
    vector<int> A(N);
    for (int i=0;i<N;i++) cin >> A.at(i);
    bubbleSort(A, N, change_cnt);
    for (int i=0;i<N;i++) {
        cout << A.at(i);
        if (i==N-1) break;
        cout << ' ';
    }
    cout << endl;
    cout << change_cnt << endl;
}
