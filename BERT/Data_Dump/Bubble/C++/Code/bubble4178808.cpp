#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, arr[100], cnt = 0;
    cin >> n;
    for(size_t i = 0; i < n; i++) cin >> arr[i];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - 1 - i; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                cnt++;
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    for(size_t i = 0; i < n; i++)
    {
        cout << arr[i];
        if(i < n - 1) cout << " ";
    }
    cout << endl << cnt << endl;

    return 0;
}

