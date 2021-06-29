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
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < N - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                cnt++;
            }
        }
    }
    PrintVector(A, N);
    cout << cnt << endl;

    return 0;
}
