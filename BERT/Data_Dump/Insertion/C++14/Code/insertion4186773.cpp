#include <bits/stdc++.h>
using ll = long long int;
using namespace std;

void PrintVector(vector<int> A, int N)
{
    for (int i = 0; i < N; i++)
    {
        if (i != N - 1)
        {
            cout << A[i] << ' ';
        }
        else
        {
            cout << A[i] << endl;
        }
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    PrintVector(A, N);
    for (int i = 1; i < N; i++)
    {
        int pivot = A[i];
        int j = i - 1;
        while ((j >= 0) && (A[j] > pivot))
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = pivot;
        PrintVector(A, N);
    }

    return 0;
}
