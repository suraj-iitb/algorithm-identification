#include <iostream>
#define MAX 500000
#define SENTINEL 2000000000
using namespace std;

int L[MAX / 2 + 2];
int R[MAX / 2 + 2];
int cnt = 0;

void merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    for(int i = 0; i < n1; i++)
        L[i] = A[left + i];
    for(int i = 0; i < n2; i++)
        R[i] = A[mid + i];
    L[n1] = SENTINEL;
    R[n2] = SENTINEL;
    int i = 0;
    int j = 0;
    for(int k = left; k < right; k++)
    {
        cnt++;
        if(L[i] <= R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
    }
}

void mergesort(int A[], int left, int right)
{
    int mid = (left + right) / 2;
    if(left + 1 < right)
    {
        mergesort(A, left, mid);
        mergesort(A, mid, right);
        merge(A, left, mid, right);
    }
}

int main()
{
    int size;
    int A[MAX];
    cin >> size;
    for(int i = 0; i < size; i++)
        cin >> A[i];
    mergesort(A, 0, size);
    for(int i = 0; i < size; i++)
    {
        if(i)
            cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}

