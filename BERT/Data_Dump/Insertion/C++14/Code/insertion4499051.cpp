#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

void print(const vector<int>& arr)
{
    cout << arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        cout << " " << arr[i];
    }
    cout << endl;
}

void insertion_sort(vector<int>& arr)
{
    for (size_t i = 1; i < arr.size(); i++) {
        int target = arr[i];
        ssize_t j = i - 1;

        while (j >= 0 && arr[j] > target) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = target;

        print(arr);
    }
}

int main()
{
    size_t n;
    cin >> n;

    vector<int> arr(n);
    for (auto&& a : arr) {
        cin >> a;
    }

    print(arr);
    insertion_sort(arr);
}

