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

//#include "./lib/generic/sort.h"

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

void sortByBubble(int A[], int N){
    int flag = 1;
    int count = 0;
    for(int i=0; flag; i++){
        flag = 0;
        for(int j=N-1; j>=i+1; j--){
            if(A[j]<A[j-1]){
                std::tie(A[j], A[j-1]) = swap(A[j-1], A[j]);
                flag = 1;
                count++;
            }
        }
    }
    traceArray(A, N);
    cout << count << endl;
}

int main(){
    int  N;
    cin >> N;
    int  A[N];
    REP(i, N) cin >> A[i];
    //sort::Sort test;
    //traceArray(A, N);
    //test.sortByIntention(A, N);
    //traceArray(A, N);
    sortByBubble(A, N);

    return 0;
}
