#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

int selectionSort(int *A, int N)
{
    int c = 0;
    REP(i, N)
    {
        int min_j = i;
        FOR(j, i+1, N)
        {
            if (A[j] < A[min_j])
                min_j = j;
        }
        if (i != min_j)
        {
            swap(A[i], A[min_j]);
            c++;
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

    int c = selectionSort(a, N);

    REP(i, N)
    {
        cout << a[i];
        if (i != N - 1)
            cout << ' ';
    }

    cout << endl
         << c << endl;
}
