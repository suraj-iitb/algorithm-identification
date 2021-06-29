#include <iostream>

using namespace std;

int cnt;
int a[1010101];
int l[1010101];
int r[1010101];

void mergeSort(int a[], int left, int right);
void merge(int a[], int left, int mid, int right);

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergeSort(a, 0, n);
    cout << a[0];
    for (int i = 1; i < n; i++)
    {
        cout << ' ' << a[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}

void mergeSort(int a[], int left, int right)
{
    if (left + 1 < right)
    {
        int mid = (left + right) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid, right);
        merge(a, left, mid, right);
    }
    return;
}

void merge(int a[], int left, int mid, int right)
{
    int cnt1, cnt2;
    cnt1 = mid - left;
    cnt2 = right - mid;
    for (int i = 0; i < cnt1; i++)
    {
        l[i] = a[left + i];
    }
    for (int i = 0; i < cnt2; i++)
    {
        r[i] = a[mid + i];
    }
    l[cnt1] = 0x7FFFFFFF;
    r[cnt2] = 0x7FFFFFFF;
    int i, j;
    i = 0;
    j = 0;
    for (int k = left; k < right; k++)
    {
        cnt++;
        if (l[i] <= r[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
    }
    return;
}
