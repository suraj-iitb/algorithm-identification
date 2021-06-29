#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

//マクロ
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 999999999

//debug
#define dump(x) cout << #x << " = " << (x) << endl;

//配列の要素を順番に出力
void trace(int A[], int N){
    int i;
    for (i = 0; i < N; i++){
        if (i>0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

///////////////////////////////////////////////////////////////
//ALDS1_2_b
//Selection Sort

void selection_sort(int A[], int N, int& count){
    int i, j, minj;
    for (i=0; i<N; i++){
        minj = i;
        for (j=i; j<N; j++){
            if (A[j] < A[minj]){
                minj = j;
            }
        }
        swap(A[i], A[minj]);
        if (i != minj) count++;
    }
}

int main(){
    const int N_MAX = 100;
    int A[N_MAX], N, count;
    count = 0;
    scanf("%d", &N);
    REP(i, N) scanf("%d", &A[i]);
    selection_sort(A, N, count);
    trace(A, N);
    printf("%d\n", count);
    return 0;
}
