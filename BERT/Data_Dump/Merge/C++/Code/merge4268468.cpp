#include <iostream>
#include <limits.h>
#include <fstream>
#define N 500000+1
#define M 250000+1
using namespace std;

int L[M], R[M];

int Merge(int A[], int left, int mid, int right)
{

    int times = 0;
    int n1 = mid - left;
    int n2 = right - mid;
    int i, j, k;
    for (i = 0; i < n1; i++)
    {
       L[i] = A[left+i];
    }
    for (i = 0; i < n2; i++)
    {
        R[i] = A[mid+i];
    }
    L[n1] = R[n2] = INT_MAX;
    i = j = 0;
    for (k = left; k < right; k++)
    {
        if (L[i] <= R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
        times++;
    }
    return times;
}
int Merge_Sort(int A[], int left, int right)
{
    int mid;
    int cb_time = 0;
    if (left + 1 < right)
    {
        mid = (left+right)/2;
        cb_time += Merge_Sort(A, left, mid);
        cb_time += Merge_Sort(A, mid, right);
        cb_time += Merge(A, left, mid, right);
    }
    return cb_time;
}
int main()
{
    int i, n;
    int cb_times;
    int A[N];
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> A[i];
    cb_times = Merge_Sort(A, 0, n);

    for (i = 0; i < n; i++)
    {
        if (i)
            cout << " ";
        cout << A[i];
    }
    cout << endl << cb_times << endl;
    return 0;
}

