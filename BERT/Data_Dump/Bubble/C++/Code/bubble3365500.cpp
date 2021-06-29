#include <iostream>
#include <algorithm>
using namespace std;
int MAX = 200;

int bubbleSort(int *A, int n)
{
    bool flag = 1;
    int sw = 0;
    while (flag)
    {
        flag = 0;
        for (int i = n - 1; i > 0; --i)
        {
            if (A[i] < A[i - 1])
            {
                int temp = A[i];
                A[i] = A[i - 1];
                A[i - 1] = temp;
                flag = 1;
                sw++;
            }
        }
    }
    return sw;
}

int main()
{
    int A[MAX];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> A[i];

    int sw = bubbleSort(A, n);

    for (int k = 0; k < n; k++)
    {
        if (k > 0)
            cout << " ";
        cout << A[k];
    }
    cout << endl;
    cout << sw << endl;

    return 0;
}
