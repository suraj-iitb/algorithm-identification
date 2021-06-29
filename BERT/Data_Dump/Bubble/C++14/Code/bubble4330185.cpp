#include <iostream>
#include <vector>
using namespace std;
const long INF = 1e9;
const long MOD = 1e9 + 7;
#define repi(i, n, init) for (int i = init; i < int(n); i++)

int bubbleSort(vector<int> &A)
{
    bool state = true;
    int cnt = 0;
    while (state)
    {
        state = false;
        repi(i, A.size(), 1)
        {
            if (A[i] < A[i - 1])
            {
                swap(A[i], A[i - 1]);
                state = true;
                cnt++;
            }
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
    int t = bubbleSort(A);
    repi(i, n, 0)
    {
        cout << A[i] << ((i + 1) % n ? " " : "");
    }
    cout << endl
         << t << endl;
    return 0;
}
