#include <bits/stdc++.h>
using namespace std;

int selection(vector<int> &);

int main(int argc, char const *argv[])
{
    int n = 0;
    cin >> n;

    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int cnt = selection(a);

    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << " ";
    }
    cout << a[n - 1] << endl
         << cnt << endl;

    return 0;
}

int selection(vector<int> &a)
{
    int cnt = 0;
    for (int i = 0; i < (int) a.size(); i++)
    {
        int min_i = i;
        for (int j = i + 1; j < (int) a.size(); j++) {
            if (a[j] < a[min_i]) {
                min_i = j;
            }
        }
        if (a[i] > a[min_i]) {
            int temp = a[i];
            a[i] = a[min_i];
            a[min_i] = temp;
            cnt++;
        }
    }
    return cnt;
}

