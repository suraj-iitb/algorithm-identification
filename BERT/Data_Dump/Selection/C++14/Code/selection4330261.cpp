#include <iostream>
#include <vector>
using namespace std;
const long INF = 1e9;
const long MOD = 1e9 + 7;
#define repi(i, n, init) for (int i = init; i < int(n); i++)

int selectionSort(vector<int> &A)
{
    int m, cnt = 0;
    repi(i, A.size(), 0)
    {
        m = i;
        repi(j, A.size(), i + 1)
        {
            if (A[j] < A[m])
            {
                m = j;
            }
        }
        if (A[i] != A[m])
        {
            cnt++;
            swap(A[i], A[m]);
        }
    }
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    repi(i, n, 0)
    {
        cin >> A[i];
    }
    int cnt = selectionSort(A);
    repi(i, n, 0)
    {
        cout << A[i] << ((i + 1) % n ? " " : "");
    }
    cout << endl
         << cnt << endl;

    return 0;
}
