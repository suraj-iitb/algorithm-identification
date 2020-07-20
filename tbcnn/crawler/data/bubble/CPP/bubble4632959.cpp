#include <iostream>
using namespace std;

void bubbleSort(int A[], int N) {
    /// ソート後の配列と交換回数を標準出力する
    bool flag = true;
    int count = 0;
    while (flag) {
        flag = false;
        for (int j = N - 1; j >= 1; j--)
        {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j-1]);
                count++;
                flag = true;
            }
        }
    }
    for (int i = 0; i < N - 1; i++) {
        cout << A[i] << " ";
    }
    cout << A[N-1] << "\n" << count << endl;
}

int main() {
    int N;
    int A[1000];
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    bubbleSort(A, N);
    return 0;
}
