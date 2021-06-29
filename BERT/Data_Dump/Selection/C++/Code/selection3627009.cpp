#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int selectionSort(int array[], int N) {
    // counter
    int sw = 0;

    for (int i = 0; i < N; i++ ) {
        int minj = i;
        for (int j = i; j < N; j++) {
            if (array[minj] > array[j]) {
                minj = j;
            }
        }

        if (minj != i) {
            swap(array[i], array[minj]);
            sw++;
        }
    }

    return sw;
}

// 配列の要素を順番に出力
void trace(int A[], int N) {
    for (int i = 0; i < N; i++) {
        cout << A[i];
        if (i < N - 1) cout << ' ';
    }
    cout << endl;
}

int main(void) {
    int N;
    int A[100];
    cin >>  N;

    for (int i =0; i < N; i ++)  cin >> A[i];
    int count = selectionSort(A, N);
    
    trace(A, N);
    cout << count << endl;

    return 0;
}
