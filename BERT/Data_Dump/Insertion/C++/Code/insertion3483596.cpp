#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define IFOR(i,a) for(int i=(a);;i++)
#define REP(i,n)  FOR(i,0,n)
#define debug(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define INPUT FILE *fp; fp=fopen("input.text","r");

//配列の要素を順番に出力
void trace(int A[], int N)
{
    int i;
    for (i = 0; i < N; i++) {
        if(i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

//挿入ソート(0オリジン) trace関数使ってる!!
void insertionSort(int A[], int N){
    int j, i, v;
    for (i = 1; i < N; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        trace(A, N);
    }
}

int main() {
    int N;
    cin >> N;
    int A[100];
    for (int i=0; i < N; i++) cin >> A[i];
    trace(A, N);
    insertionSort(A, N);
    return 0;
}



