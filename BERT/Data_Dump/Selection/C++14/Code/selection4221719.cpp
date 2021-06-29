#include <bits/stdc++.h>
using namespace std;

int selection_sort(int[], int);
void output(int[], int);

int main()
{
    int
        n,
        arr[110],
        result;

    cin >> n;

    for (int i=0; i<n; ++i) {
        cin >> arr[i];
    }

    result = selection_sort(arr, n);
    output(arr, n);
    cout << result << endl;
    return 0;
}

int selection_sort(int arr[], int n)
{
    int
        result=0,
        minv;
    //print result!
    for (int i=0; i<n; ++i) {
            minv = i;
        for (int j=i; j<n; ++j) {
            if (arr[j] < arr[minv]) {
                minv = j;
            }
        }
        swap(arr[i], arr[minv]);
        if (i != minv) result++;
    }
    return result;
}

void output(int arr[], int n)
{
    for (int i=0; i<n; ++i) {
        if (i) cout << " ";
        cout << arr[i];
    }
    cout << endl;
}

