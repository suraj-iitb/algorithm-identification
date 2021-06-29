// 選択ソート

#include <iostream>
using namespace std;

int selectionSort(int A[], int N);

int main()
{
    int N, A[100], sw;

    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];

    sw = selectionSort(A, N);

    for (int i=0; i<N; i++) {
        if (i) cout << ' ';
        cout << A[i];
    }
    cout << '\n' << sw << '\n';
    return 0;
}

int selectionSort(int A[], int N)
{
    int sw = 0;
    for (int i=0; i<N; i++) {
        int minj = i;  // i番目に小さい数のインデックス？
        for (int j=i; j<N; j++) {
            if (A[j] < A[minj]) {
                minj = j;
            }
        }
        swap(A[i], A[minj]);
        if (i!=minj) sw++;
    }
    return sw;
}
