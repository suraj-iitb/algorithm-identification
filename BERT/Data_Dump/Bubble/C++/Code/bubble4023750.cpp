#include <bits/stdc++.h>
using namespace std;

long long Bubble(int arr[], int n)
{
    int i, j;
    long long cnt = 0;

    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                cnt++;
            }
        }
    }
    for(i = 0; i < n; i++)
        cout << arr[i] << (i == n-1 ? '\n' : ' ');
    //cout << endl;
    return cnt;
}

int main()
{
    int n, i;
    cin >> n;
    int arr[n];
    for(i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int p = Bubble(arr, n);
    cout << p << endl;
}

