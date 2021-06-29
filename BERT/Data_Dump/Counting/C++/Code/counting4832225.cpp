#include <iostream>

using namespace std;

int ori[10101010];
int ans[10101010];
int cnt[10101010];

void countingSort(int ori[], int ans[], int cnt[], int limit, int n);

int main()
{
    int n, limit;
    cin >> n;
    limit = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> ori[i];
        cnt[ori[i]]++;
        limit = max(limit, ori[i]);
    }
    countingSort(ori, ans, cnt, limit, n);
    for (int i = 0; i < n; i++)
    {
        if (i)
        {
            cout << " ";
        }
        cout << ans[i];
    }
    cout << endl;
    return 0;
}

void countingSort(int ori[], int ans[], int cnt[], int limit, int n)
{
    for (int i = 1; i <= limit; i++)
    {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        ans[cnt[ori[i]] - 1] = ori[i];
        cnt[ori[i]]--;
    }
    return;
}
