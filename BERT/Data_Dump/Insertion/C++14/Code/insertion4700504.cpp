#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for (int i = 0; i < (int)(n); i++)

void trace(vector<int>& A)
{
    for(int i = 0; i < A.size(); i++)
    {
        if(i < A.size() - 1)
        {
            cout << A[i] << " ";
        }
        else
        {
            cout << A[i];
        }
    }
    cout << endl;
}

void insertionSort(vector<int>& A, int N)
{
    trace(A);
    for (int i = 1; i < N; i++)
    {
        int v = A[i];
        int j = i - 1;
        while ((j >= 0) && (A[j] > v))
        {
            A[j + 1] = A[j];
            A[j] = v;
            j--;
        }
        trace(A);
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    REP(i, N)
        cin >> A[i];

    insertionSort(A, N);

    return 0;
}
