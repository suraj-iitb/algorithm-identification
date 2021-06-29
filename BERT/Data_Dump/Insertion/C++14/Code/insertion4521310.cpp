#include <bits/stdc++.h> //全てのヘッダファイルをインクルード

//ループ
#define REP(i, n) for(int i = 0; i < n; i++) //普通のループ
#define REPR(i, n) for(int i = n; i >= 0; i--) //逆ループ
#define FOR(i, m, n) for(int i = m; i < n; i++) //最初の数値を指定したループ

//型名省略
typedef long long ll;

//配列要素数
static const int MAX = 200000;

using namespace std;

//#include "./lib/string.h"

std::tuple<int, int> swap(int num1, int num2){
     return std::forward_as_tuple(num1, num2);
}

void traceArray(int A[], int N){
    for(int i=0; i<N; i++){
        cout << A[i];
        if(i!=N-1){
            cout  << " ";
        }
    }
    cout << endl;
}

void insertSort(int A[], int N){
    int i, j, v, k;
    for(i=1; i<N; i++){
        v=A[i];
        j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        traceArray(A, N);
    }
}

int main(){
    int  N;
    cin >> N;
    int  A[N];
    REP(i, N) cin >> A[i];
    traceArray(A, N);
    insertSort(A, N);

    return 0;
}
