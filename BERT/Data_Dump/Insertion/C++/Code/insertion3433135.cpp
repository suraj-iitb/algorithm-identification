#include <iostream>
using namespace std;

void print(int A[], int n)
{
    for (int i = 0; i != n; ++i)
    {
        if (i > 0)
        {
            cout << " ";
        }

        cout << A[i];
    }

    cout << endl;
}

void insertionSort(int A[], int n)
{
    for (int i = 1; i != n; ++i)
    {
        int v = A[i],
            j = i - 1;

        while (j >= 0 && A[j] > v)
        {
            A[j+1] = A[j];
            --j;
        }

        A[j+1] = v;

        print(A, n);
    }
}

int main()
{
    int A[100], n;

    cin >> n;

    for (int i = 0; i != n; ++i)
    {
        cin >> A[i];
    }

    print(A, n);
    insertionSort(A, n);

    return 0;
}
