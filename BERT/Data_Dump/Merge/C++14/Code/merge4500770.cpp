#include <bits/stdc++.h>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000

int L[MAX/2+2], R[MAX/2+2];
int counter;

void Merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left;
    int n2 = right - mid;
    for (int i=0; i<n1; ++i) L[i] = A[left+i];
    for (int i=0; i<n2; ++i) R[i] = A[mid+i];
    L[n1] = R[n2] = SENTINEL;
    int i=0, j=0;
    for (int k = left; k<right; ++k) {
        counter++;
        if (L[i] <= R[j]) {
            A[k] = L[i++];
        } else {
            A[k] = R[j++];
        }
    }
}
void MergeSort(int A[], int left, int right)
{
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        MergeSort(A, left, mid);
        MergeSort(A, mid, right);
        Merge(A, left, mid, right);
    }
}
int main()
{
    int A[MAX];
    counter=0;
    int n; cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> A[i];
    }

    MergeSort(A, 0, n);

    for (int i=0; i<n; ++i) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;

    cout << counter << endl;
    return 0;
}

