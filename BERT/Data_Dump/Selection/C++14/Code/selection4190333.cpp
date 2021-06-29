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
    int cnt = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int pivot = i;
        for (int j = i + 1; j < N; j++)
        {
            if (A[pivot] > A[j])
            {
                pivot = j;
            }
        }
        if (i != pivot)
        {
            swap(A[i], A[pivot]);
            cnt++;
        }
    }
    PrintVector(A, N);
    cout << cnt << endl;

    return 0;
}
