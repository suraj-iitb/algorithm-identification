#include <iostream>
#include <climits>

using namespace std;


#define MAX 500000


long L[MAX/2+1], R[MAX/2+1];
long cnt = 0;
void merge(long A[], long l, long r, long m)
{
    long ln = m - l;
    long rn = r - m;

    for (long i = 0; i < ln; i++)
        L[i] = A[l + i];
    for (long i = 0; i < rn; i++)
        R[i] = A[m + i];

    L[ln] = INT_MAX;
    R[rn] = INT_MAX;

    long li, ri;
    li = ri = 0;

    for (long i = l; i < r; i++) {
        cnt++;
        if (L[li] <= R[ri])
            A[i] = L[li++];
        else
            A[i] = R[ri++];
    }
}


void merge_sort(long A[], long l, long r)
{
    if (r - l > 1) {
        long m = (l + r) / 2;
        merge_sort(A, l, m);
        merge_sort(A, m, r);
        merge(A, l, r, m);
    }
}


long A[MAX];
int main()
{
    long n;
    cin >> n;

    for (long i = 0; i < n; i++)
        cin >> A[i];

    merge_sort(A, 0, n);

    for (long i = 0; i < n - 1; i++) {
        cout << A[i] << " ";
    }
    cout << A[n - 1] << endl;
    cout << cnt << endl;
    return 0;
}


