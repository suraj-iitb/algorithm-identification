#include <iostream>
#define swap(type, x, y) do { type t = x; x = y; y = t; } while (0)
using namespace std;

void show(int A[], int N)
{
    for (int i = 0; i < N; i++) {
        if (i == N - 1)
            cout << A[i] << endl;
        else
            cout << A[i] << ' ';
    }
}

int selectionSort(int A[], int N)
{
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int min = i;
        for (int j = i; j < N; j++) {
            if (A[j] < A[min])
                min = j;
        }
        if (min != i) {
            swap(int, A[i], A[min]);
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int n, *arr, cnt;

    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cnt = selectionSort(arr, n);

    show(arr, n);
    cout << cnt << endl;

    delete[] arr;
}
