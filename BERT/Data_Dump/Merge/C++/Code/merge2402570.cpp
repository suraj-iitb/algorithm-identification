#include <iostream>

#define MAX_NUM 500000
using namespace std;

int merge(int A[], int left, int right, int mid)
{
    int n1 = mid - left;
    int n2 = right - mid;
    int L[MAX_NUM], R[MAX_NUM];

    for (int i = 0; i < n1; ++i)
        L[i] = A[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = A[mid + i];
    L[n1] = 1000000000;
    R[n2] = 1000000000;

    int i = 0, j = 0;
    for (int k = left; k < right; ++k) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
    return i + j;
}

int mergeSort(int A[], int left, int right)
{
    int count = 0;
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        count += mergeSort(A, left, mid);
        count += mergeSort(A, mid, right);
        count += merge(A, left, right, mid);
    }
    return count;
}

int main()
{
    int n;
    int S[MAX_NUM];
    
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> S[i];

    int count = mergeSort(S, 0, n);
    
    for (int i = 0; i < n - 1; ++i)
        cout << S[i] << " ";
    cout << S[n-1] << endl;
    
    cout << count << endl;
    return 0;
}
