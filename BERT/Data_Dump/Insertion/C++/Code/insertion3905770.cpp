#include <iostream>
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

void insertionSort(int A[], int N)
{
    show(A, N);
    for (int i = 1; i < N; i++) {
        int j = i - 1, v = A[i];
        while (j >= 0 && A[j] > v) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        show(A, N);
    }
}

int main()
{
    int *arr, n;

    cin >> n;
    arr = new int[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    insertionSort(arr, n);

    delete[] arr;  
}
