// 挿入ソート 2018/11/16

#include <iostream>
using namespace std;

void insertionSort(int *A, int n);

int main()
{
    int N, A[1000];

    cin >> N;
    for (int i=0; i<N; i++)
        cin >> A[i];

    // 入力直後の並び
    for (int i=0; i<N-1; i++)
        cout << A[i] << ' ';
    cout << A[N-1] << '\n';
    insertionSort(A, N);
    return 0;
}

void insertionSort(int *A, int N)
{
    int v, i, j;
    for (i=1; i<N; i++) {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        for (int k=0; k<N-1; k++)
            cout << A[k] << ' ';
        cout << A[N-1] << '\n';
    }
}
