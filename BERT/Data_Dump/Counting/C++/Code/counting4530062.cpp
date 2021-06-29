#include <bits/stdc++.h>
using namespace std;
void Countingsort(const unsigned short *arrayA, unsigned short *arrayB, int n, unsigned short max)
{
    int arrayC[max + 1] = {};
    for (int j = 0; j < n; ++j)
        arrayC[arrayA[j]]++;
    for (int i = 1; i <= max; ++i)
        arrayC[i] += arrayC[i - 1];
    for (int j = n - 1; j >= 0; --j)
    {
        arrayB[arrayC[arrayA[j]]] = arrayA[j];
        arrayC[arrayA[j]]--;
    }
}
int main()
{
    int n;
    cin >> n;
    unsigned short A[n], B[n + 1] = {}, max(0);
    for (int i = 0; i < n; ++i)
    {
        scanf("%hu", &A[i]);
        if (max < A[i])
            max = A[i];
    }
    Countingsort(A, B, n, max);
    for (int i = 1; i < n; ++i)
        printf("%d ", B[i]);
    cout << B[n] << endl;
}
