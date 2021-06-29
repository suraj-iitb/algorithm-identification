#include <bits/stdc++.h>
using namespace std;

int output(int arr[], int n)
{
    for (int i=0; i<n; ++i) {
        if (i > 0) cout << " ";
        cout << arr[i];
    }
    cout << endl;
}

void sort(int arr[], int n)
{
    int j, v;
    for (int i=1; i<n; ++i) {
        j = i - 1;
        v = arr[i];
        while (j>=0 && arr[j] > v) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = v;
        output(arr, n);
    }
}

int main()
{
    int n, j, v;
    int arr[110];
    cin >> n;
    
    for (int i=0; i<n; ++i) cin >> arr[i];
    
    output(arr, n);
    sort(arr, n);
    
    return 0;
}
