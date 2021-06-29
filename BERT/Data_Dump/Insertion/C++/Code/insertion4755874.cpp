#include <bits/stdc++.h>
using namespace std;

void printVectorInt(vector<int> A)
{
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i];
        if (i == A.size() - 1)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
    }
}

vector<int> insertionSort(vector<int> A, int N)
{
    int v,j;
    for (int i = 1; i < N; i++)
    {
        v = A[i];
        for (j = i - 1; j >= 0 && A[j] > v; j--)
        {
            A[j + 1] = A[j];
        }
        A[j + 1] = v;
        printVectorInt(A);
    }
    return A;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    printVectorInt(a);
    insertionSort(a, n);
    return 0;
}
