#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

int bubbleSort(int *A, int N)
{
    int c = 0;
    bool flag = true;
    while (flag)
    {
        flag = false;
        FOR(i, 1, N)
        {
            if(A[i] < A[i-1])
            {
                swap(A[i], A[i - 1]);
                c++;
                flag = true;
            }
        }
    }
    return c;
}

int main()
{
    int a[100], N;
    cin >> N;
    REP(i, N)
    {
        cin >> a[i];
    }

    int c = bubbleSort(a, N);

    REP(i, N)
    {
        cout << a[i];
        if (i != N-1)
            cout << ' ';
    }

    cout << endl << c << endl;
}
