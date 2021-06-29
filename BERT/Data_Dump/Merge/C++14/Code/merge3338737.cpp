#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

void m_sort(vector<long long int> &, int, int, long long int &);
void merge(vector<long long int> &, int, int, int, long long int &);

int main(int argc, char const *argv[])
{
    // ios::sync_with_stdio(false);

    int n = 0;
    // cin >> n;
    scanf("%d", &n);

    vector<long long int> arr(n, 0);
    REP(i, n)
    {
        // cin >> arr[i];
        scanf("%lld", &arr[i]);
    }

    long long int cnt = 0;
    m_sort(arr, 0, n, cnt);

    REP(i, n - 1) {
        // cout << arr[i] << " ";
        printf("%lld ", arr[i]);
    }
    // cout << arr[n - 1] << endl;
    printf("%lld\n", arr[n - 1]);
    // cout << cnt << endl;
    printf("%lld\n", cnt);

    return 0;
}

void m_sort(vector<long long int> &arr, int left, int right, long long int &cnt)
{
    if (right > left + 1)
    {
        int mid = (left + right) / 2;
        m_sort(arr, left, mid, cnt);
        m_sort(arr, mid, right, cnt);

        merge(arr, left, mid, right, cnt);
    }
}

void merge(vector<long long int> &arr, int left, int mid, int right, long long int &cnt)
{
    int na = mid - left, nb = right - mid;
    vector<long long int> a(na + 1, 0), b(nb + 1, 0);

    const int INFTY = 1000000001;

    REP(i, na) {
        a[i] = arr[i + left];
    }
    a[na] = INFTY;

    REP(i, nb) {
        b[i] = arr[i + mid];
    }
    b[nb] = INFTY;

    int i = 0, j = 0;
    FOR(k, left, right) {
        cnt++;
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            i++;
        }
        else
        {
            arr[k] = b[j];
            j++;
        }
    }
}
