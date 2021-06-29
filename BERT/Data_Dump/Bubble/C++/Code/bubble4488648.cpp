#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, ans(0);
    cin >> N;
    int A[N];
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    bool flag(true);
    while (flag)
    {
        flag = !flag;
        for (int j = N - 1; j >= 1; --j)
        {
            if (A[j] < A[j - 1])
            {
                swap(A[j], A[j - 1]);
                ans++;
                flag = true;
            }
        }
    }
    for (int i = 0; i < N; ++i)
    {
        cout << A[i] << flush;
        if (i != N - 1)
            cout << ' ' << flush;
    }
    cout << endl
         << ans << endl;
}
