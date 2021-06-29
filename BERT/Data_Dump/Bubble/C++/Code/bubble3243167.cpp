// バブルソート

#include <iostream>
using namespace std;

void bubbleSort(int *A, int N);

int main()
{
    int N, A[100];
    cin >> N;
    for (int i=0; i<N; i++)
        cin >> A[i];
    bubbleSort(A, N);
    return 0;
}

void bubbleSort(int *A, int N)
{
    int flag = 1;  // 逆の隣接要素が存在する
    int tmp, count = 0;
    while (flag) {
        flag = 0;
        for (int j=N-1; j>0; j--) {
            if (A[j] < A[j-1]) {
                count++;
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                flag = 1;
            }
        }
    }
    for (int i=0; i<N-1; i++)
        cout << A[i] << ' ';
    cout << A[N-1] << '\n';
    cout << count << '\n';
}
