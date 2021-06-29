#include <iostream>
using namespace std;

void log(int A[], int n)
{
    for (int i = 0; i < n; ++i) {
        cout << A[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n; ++i) {
        int tmp = A[i];
        int j = i;
        while (j > 0 && A[j-1] > tmp) {
            A[j] = A[j-1];
            --j;
        }
        A[j] = tmp;
        log(A, n);
    }
}

int main()
{
    // Input
    int n;
    cin >> n;

    int A[100];
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        A[i] = a;
    }

    log(A, n);
    InsertionSort(A, n);

    return 0;
}
