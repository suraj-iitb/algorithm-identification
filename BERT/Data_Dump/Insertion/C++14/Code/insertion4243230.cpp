#include <iostream>
using namespace std;

void trace(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << A[i] << endl;
        }
        else
        {
            cout << A[i] << ' ';
        }
    }
}

void insertSort(int A[], int n)
{
    int v, j;
    for (int i = 1; i < n; i++)
    {
        v = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        trace(A, n);
    }
}

int main()
{
    int n, A[100];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    trace(A, n);
    insertSort(A, n);
    return 0;
}
