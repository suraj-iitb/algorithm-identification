#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, ans(0);
    cin >> N;
    int A[N];
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = 0; i < N - 1; ++i)
    {
        int minj = i;
        for (int j = minj + 1; j < N; ++j)
        {
            if (A[j] < A[minj])
            {
                minj = j;
            }
        }
        if (i != minj)
        {
            swap(A[i], A[minj]);
            ans++;
        }
    }
    for (int i = 0; i < N; ++i)
    {
        cout << A[i] << flush;
        if (i < N - 1)
            cout << ' ' << flush;
    }
    cout << endl
         << ans << endl;
}
