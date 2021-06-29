#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, arr[100];
    cin >> n;
    for(size_t i = 0; i < n; i++) cin >> arr[i];

    for(size_t i = 0; i < n; i++)
    {
        cout << arr[i];
        if(i < n - 1)
            cout << " ";
    }
    cout << endl;
    for(size_t i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;

        for(size_t i = 0; i < n; i++)
        {
            cout << arr[i];
            if(i < n - 1)
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}

