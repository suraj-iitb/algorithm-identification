#include <bits/stdc++.h>
#define SIZE 500000
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using namespace std;
void merge(int *array, int left, int mid, int right, int &count)
{
    int n1 = mid - left;  //1
    int n2 = right - mid; //1
    int L[n1 + 1], R[n2 + 1];
    rep(i, n1) L[i] = array[left + i];
    rep(i, n2) R[i] = array[mid + i];
    L[n1] = 2147383657, R[n2] = 2147383657;
    int i(0), j(0);
    for (int k = left; k < right; ++k)
    {
        count++;
        if (L[i] <= R[j])
            array[k] = L[i++];
        else
            array[k] = R[j++];
    }
}
void mergesort(int *array, int left, int right, int &count)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergesort(array, left, mid, count);
        mergesort(array, mid, right, count);
        merge(array, left, mid, right, count);
    }
}
int main()
{
    int n;
    cin >> n;
    int s[n];
    int count(0);
    rep(i, n) cin >> s[i];
    mergesort(s, 0, n, count);
    rep(i, n)
    {
        cout << s[i] << flush;
        if (i < n - 1)
            cout << ' ' << flush;
    }
    cout << endl
         << count << endl;
}
