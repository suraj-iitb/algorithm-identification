#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxC = 10005;
const int MaxA = 2000005;
const int MaxB = 2000005;

int A[MaxA], B[MaxB], C[MaxC];
void CountingSort(int A[], int n, int k)
{
    memset(C, 0, sizeof(C));
    for(int i=0; i<n; i++)
    {
        C[A[i]]++;
    }
    for(int i=1; i<=k; i++)
    {
        C[i] += C[i-1];
    }
    for(int i=n-1; i>=0; i--)
    {
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
}
int main()
{
    int n, k = 0;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
        if(k<A[i]) k = A[i];
    }
    CountingSort(A, n, k);
    for(int i=1; i<=n-1; i++)
        cout << B[i] << " ";
    cout << B[n] << endl;
    return 0;
}

