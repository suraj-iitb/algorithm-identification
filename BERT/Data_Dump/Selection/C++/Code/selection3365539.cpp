#include <iostream>
#include <algorithm>
using namespace std;
int MAX = 200;

int selectionSort(int *A, int n)
{
    int sw = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minj = i;
        for (int j = i; j < n; j++)
        {
            if (A[j] < A[minj])
            {
                minj = j;
            }
        }
        int temp = A[i];
        A[i] = A[minj];
        A[minj] = temp;
        if (i != minj)
            sw++;
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

    int sw = selectionSort(A, n);

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
