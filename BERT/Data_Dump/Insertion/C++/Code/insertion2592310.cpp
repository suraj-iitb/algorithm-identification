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
    int N = 0;

    cin >> N;

    vector<int> A(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (i > 0)
        {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;

    for (int i = 1; i < N; i++)
    {
        int value = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > value)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = value;
        for (int k = 0; k < N; k++)
        {
            if (k > 0)
            {
                cout << " ";
            }
            cout << A[k];
        }
        cout << endl;
    }

    return 0;
}
