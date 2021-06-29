#include <bits/stdc++.h>
using namespace std;

int bubble_sort(int arr[], int n)
{
    int num=0, index=0;
    bool flag = true;

    while (flag) {
        flag = false;
        for (int j=n-1; j>=index+1; --j) {
            if (arr[j-1] > arr[j]) {
                swap(arr[j-1], arr[j]);
                num++;
                flag = true;
            }
        }
        index++;
    }
    return num;
}

int main()
{
    int n, arr[110], result;
    cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> arr[i];
    }
    
    result = bubble_sort(arr, n);
    
    for (int i=0; i<n; ++i) {
        if (i) cout << " ";
        cout << arr[i];
    }
    cout << endl;
    cout << result << endl;
    return 0;
}

