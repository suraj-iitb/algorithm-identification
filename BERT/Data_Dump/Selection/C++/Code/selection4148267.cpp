#include <iostream>
#include <algorithm>
using namespace std;
static const int MAX = 100;

void trace(int *A, int N) {
    for ( int i = 0; i < N; ++i ) {
        if ( i > 0 ) {
            cout << ' ';
        }
        cout << A[i];
    }
    cout << endl;
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int BubbleSort(int *A, int N) {
    int flag = 0;
    int sw = 0;
    int cnt = 0;
    do {
        flag = 0;
        for (int i = N - 1; i > cnt; --i) {
            if (A[i] < A[i - 1]) {
                swap(A + i, A + i - 1);
                sw++;
                flag = 1;
            }
        }
        cnt++;
    }while ( flag == 1 );
    return sw;
}

int SelectionSort(int *A, int N) {
    int mini;
    int cnt = 0;
    for ( int i = 0; i < N; ++i ) {
        mini = i;
        for ( int j = i; j < N; ++j ) {
            if ( A[mini] > A[j] ) {
                mini = j;
            }
        }
        if ( A[mini] < A[i]) {
            swap(A + mini, A + i);
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int A[MAX],N;
    int ans;

    cin >> N;
    for ( int i = 0; i < N; ++i ) cin >> A[i];

    ans = SelectionSort(A,N);

    trace(A,N);
    cout << ans << endl;


    return 0;
}
