#include <iostream>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000

int L[MAX / 2 + 2], R[MAX / 2 + 2];
int cnt;

int merge(int A[], int N, int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i = 0; i < n1; i++)
    {
        L[i] = A[left + i];
    }
    for (int i = 0; i < n2; i++)
    {
        R[i] = A[mid + i];
    }
    L[n1] = R[n2] = SENTINEL;
    int i = 0, j = 0;
    for (int k = left; k < right; k++)
    {
        cnt++;
        if (L[i] <= R[j])
        {
            A[k] = L[i++];
        }
        else
        {
            A[k] = R[j++];
        }
    }
}

int mergeSort(int A[], int N, int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(A, N, left, mid);
        mergeSort(A, N, mid, right);
        merge(A, N, left, mid, right);
    }
}

int main()
{
    int A[MAX], n, i;
    cnt = 0;
    cin >> n;
    // int A[] = {8, 5, 9, 2, 6, 3, 7, 1, 10, 4};
    // int n = sizeof(A) / sizeof(*A);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    mergeSort(A, n, 0, n);
    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
