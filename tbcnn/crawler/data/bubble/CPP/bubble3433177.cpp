#include <iostream>
using namespace std;

int bubbleSort(int A[], int n)
{
    bool flat = true;
    int j = 0,
        sw = 0;

    while (flat)
    {
        flat = false;

        for (int i = n-1; i > j; --i)
        {
            if (A[i-1] > A[i])
            {
                flat = true;
                swap(A[i-1], A[i]);
                ++sw;
            }
        }

        ++j;
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

    sw = bubbleSort(A, n);

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
