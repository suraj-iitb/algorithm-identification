#include <bits/stdc++.h>
using namespace std;

void Sort(int arr[], int n)
{
    //cout << endl;
    int i, j, key;
    for(i = 1; i < n; i++)
    {
        // for(int k = 0; k < n; k++)  cout << arr[k] << " ";
        for(int k=0;k<n;k++) cout << arr[k] << (k==n-1?'\n':' ');


        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j--];
        }
        arr[j+1] = key;
    }
    for(int k=0;k<n;k++) cout << arr[k] << (k==n-1?'\n':' ');

}
int main()
{
    int n, i;
    cin >> n;
    int arr[n];
    for(i = 0; i < n; i++)
        cin >> arr[i];
    Sort(arr, n);

    return 0;
}
