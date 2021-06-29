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

void sortBySelection(int A[], int N){
    int min = 0;
    int count = 0;
    for(int i=0; i<N-1; i++){
        min = i;
        for(int j=i+1; j<N; j++){
            if(A[min]>A[j]){
                min = j;
            }
        }
        if(i!=min){
            std::swap(A[i], A[min]);
            count++;
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
    //test.sortByBubble(A, N);
    sortBySelection(A, N);
    //traceArray(A, N);

    return 0;
}
