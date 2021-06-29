#include <iostream>
using namespace std;

int selectionSort(int A[], int n)
{
    int sw = 0, minj;

    for (int i = 0; i != n-1; ++i)
    {
        minj = i;

        for (int j = i; j != n; ++j)
        {
            if (A[j] < A[minj])
            {
                minj = j;
            }
        }

        if (minj != i)
        {
            swap(A[i], A[minj]);
            ++sw;
        }
    }

    return sw;
}

int main()
{
    int A[100], n, sw;

    cin >> n;

    for (int i = 0; i != n; ++i)
    {
        cin >> A[i];
    }

    sw = selectionSort(A, n);

    for (int i = 0; i != n; ++i)
    {
       if (i > 0)
       {
           cout << " ";
       }

        cout << A[i];
    }

    cout << endl;
    cout << sw << endl;

    return 0;
}
