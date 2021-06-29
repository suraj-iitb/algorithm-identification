#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

void countingSort(vector<int> &A, vector<int> &B, int k)
{
    vector<int> C(k + 1, 0);
    for (int i = 0; i < A.size(); i++)
    {
        C[A[i]]++;
    }

    for (int i = 1; i < C.size(); i++)
    {
        C[i] += C[i - 1];
    }

    // 安定性のためにカウントダウンしていく
    for (int i = A.size() - 1; i >= 0; i--)
    {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }

    // for (int i = 0; i < A.size(); i++)
    // {
    //     B[C[A[i]] - 1] = A[i];
    //     C[A[i]]--;
    // }

    return;
}

int main()
{
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        // cin >> A[i];
        scanf("%d", &A[i]);
    }

    vector<int> B(n);
    countingSort(A, B, *max_element(A.begin(), A.end()));

    // for (int i = 0; i < n; i++)
    // {
    //     cout << B[i];
    //     if (i < n - 1)
    //     {
    //         cout << " ";
    //     }
    // }
    // cout << endl;

    for (int i = 0; i < n; i++)
    {
        printf("%d", B[i]);
        if (i < n - 1)
        {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
