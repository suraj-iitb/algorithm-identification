#include <iostream>

using namespace std;

void InsertionSort(int A[], int N)
{
    // 出力
    for (int i = 0; i < N; i++) {
        i == N - 1 ? cout << A[i] << endl : cout << A[i] << " ";
    }

    for (int i = 1; i <= N - 1; i++) {

        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;

        // 出力
        for (int i = 0; i < N; i++) {
            i == N - 1 ? cout << A[i] << endl : cout << A[i] << " ";
        }
    }
}

int main()
{
    int size = 0;
    int* list = NULL;

    // 入力
    cin >> size;
    list = new int[size];
    for (int i = 0; i < size; i++) {
        int t = 0;
        cin >> t;
        list[i] = t;
    }

    // 挿入ソート
    InsertionSort(list, size);

    delete[] list;

    return 0;
}
