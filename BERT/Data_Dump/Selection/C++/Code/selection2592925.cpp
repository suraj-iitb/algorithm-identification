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

    // int array[5] = {1,2,3,4,5};
    vector<int> A(N, 0);
    // vector<int> A(array, array + sizeof(array)/sizeof(array[0]));
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N - 1; i++)
    {
        int minv = i;
        for (int j = i + 1; j < N; j++)
        {
            if (A[minv] > A[j])
            {
                minv = j;
            }
        }
        if (minv != i)
        {
            swap(A[minv], A[i]);
            count++;
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
