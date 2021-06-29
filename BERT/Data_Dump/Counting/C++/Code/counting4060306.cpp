// 計数ソート
// 各要素の個数を数えていく。その後累積和を求め正しい位置に入るindexを求めていく
#include<bits/stdc++.h>
using namespace std;

#define MAX 10010
#define MMAX 2000010

void CountingSort(int A[], int dst[], int maxel);

int A[MMAX], B[MMAX], C[MAX];
int n;

int main(){
    cin >> n;
    int ma = INT_MIN;
    for(int i = 0; i < n; i++){
        cin >> A[i];
        ma = max(ma, A[i]);
    }

    CountingSort(A,B,ma);

    for(int i = 1; i <= n; i++){
        cout << B[i];
        if(i != n) cout << " ";
        else cout << endl;
    }
}

void CountingSort(int A[], int dst[], int maxel){
    // 計数ソート

    // 0にする
    for(int i = 0; i <= maxel; i++){
        C[i] = 0;
    }

    // カウント
    for(int i = 0; i < n; i++){
        C[A[i]]++;
    }

    // 累積和
    for(int i = 1; i <= maxel; i++){
        C[i] += C[i-1];
    }

    // dstに入れてく
    for(int i = n-1; i >= 0; i--){
        dst[C[A[i]]] = A[i];
        C[A[i]]--;
    }
}
