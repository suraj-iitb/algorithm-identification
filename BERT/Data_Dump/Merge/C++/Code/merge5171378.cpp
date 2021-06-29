#include <iostream>
using namespace std;
#define MAX 500000
#define INFTY 1e9+1
int a[MAX], cnt = 0;

void merge(int a[], int left, int mid, int right)
{
    int n1 = mid - left, n2 = right - mid;
    int L[n1 + 1], R[n2 + 1];
    for (int i = 0; i < n1; ++i) L[i] = a[left + i];
    for (int i = 0; i < n2; ++i) R[i] = a[mid + i];
    L[n1] = R[n2] = INFTY;
    int p1 = 0, p2 = 0, k;
    for (k = left; k < right; ++k)
    {
        ++cnt;
        if (L[p1] < R[p2])
            a[k] = L[p1++];
        else
            a[k] = R[p2++];
    }
}

void mergesort(int a[], int left, int right)
{
    if (left + 1 < right) {
        int mid = left + (right - left) / 2;
        mergesort(a, left, mid);
        mergesort(a, mid, right);
        merge(a, left, mid, right);
    }
}

int main()
{
    // freopen("out.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    mergesort(a, 0, n);
    for (int i = 0; i < n; ++i) {
        cout << a[i];
        if (i != n - 1) cout << " ";
    }
    cout << '\n' << cnt << endl;
    return 0;
}
