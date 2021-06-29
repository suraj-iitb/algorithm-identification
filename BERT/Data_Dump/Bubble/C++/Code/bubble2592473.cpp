#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

typedef signed long long ll;

int main(void)
{
    int N = 5;
    int count = 0;

    cin >> N;

    vector<int> A(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0, flg = 1; flg; i++)
    {
        flg = 0;
        for (int j = N - 1; j > i; j--)
        {
            if (A[j - 1] > A[j])
            {
                swap(A[j - 1], A[j]);
                count++;
                flg = 1;
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (i > 0)
        {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
    cout << count << endl;

    return 0;
}
