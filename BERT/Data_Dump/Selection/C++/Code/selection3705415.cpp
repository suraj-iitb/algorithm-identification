#include <stdio.h>
#include <iostream>
using namespace std;
static const int MAX = 100;
int main()
{
    // for i = 0 to A.length-1
    // 2     mini = i
    // 3     for j = i to A.length-1
    // 4         if A[j] < A[mini]
    // 5             mini = j
    // 6     swap A[i] and A[mini]
    int N, A[MAX], elem, mini, sw = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> elem;
        A[i] = elem;
    }

    for (int k = 0; k < N; k++)
    {
        mini = k;
        for (int j = k; j < N; j++)
        {
            if (A[j] < A[mini])
            {
                mini = j;
            }
        }
        if (k != mini)
        {
            swap(A[k], A[mini]);
            sw++;
        }
    }
    for (int j = 0; j < N; j++)
    {
        if (j)
        {
            cout << " ";
        }
        cout << A[j];
    }
    cout << endl;

    cout << sw<<endl;
    return 0;
}
