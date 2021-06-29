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

//ALDS1_2_A
//Bubble Sort

//配列の要素を順番に出力
void trace(int A[], int N){
    int i;
    for (i = 0; i < N; i++){
        if (i>0) printf(" ");
        printf("%d", A[i]);
    }
    printf("\n");
}

void bubble_sort(int A[], int N, int& count){
    int i;
    bool flag = true; //逆の隣接行列が存在する
    while (flag){
        flag = false;
        for (i = N-1; i>0; i--){
            if (A[i] < A[i-1]){
                swap(A[i], A[i-1]);
                flag = true;
                count++;
            }
        }
    }
}

int main(){
    const int N_MAX = 100;
    int A[N_MAX];
    int N;
    int count = 0;
    scanf("%d", &N);
    REP(i, N) scanf("%d", &A[i]);
    bubble_sort(A, N, count);
    trace(A, N);
    printf("%d\n", count);
    return 0;
}
