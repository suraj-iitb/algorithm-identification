#include <bits/stdc++.h>
using namespace std;

int Selection(int arr[], int n)
{
    int i, j, cnt = 0;
    for(i = 0; i < n; i++)
    {
        int mini = i;
        for(j = i; j < n; j++)
        {
            if(arr[j] < arr[mini])
                mini = j;
        }
        swap(arr[i], arr[mini]);
        if(i != mini) cnt++;
    }
    return cnt;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = Selection(arr, n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << (i == n-1 ? '\n' : ' ');
    cout << ans << endl;
    return 0;
}

