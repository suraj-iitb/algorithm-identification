#include <bits/stdc++.h>
using namespace std;

int compare = 0;

void merge(vector<int>& nums, int l, int m, int r)
{
    vector<int> left(m - l + 1); // + 1 for infinity
    vector<int> right(r - m + 1); // + 1 for infinity
    for (int i = 0; i < left.size() - 1; i++) {
        left[i] = nums[l + i];
    }
    left.back() = numeric_limits<int>::max();
    for (int i = 0; i < right.size() - 1; i++) {
        right[i] = nums[m + i];
    }
    right.back() = numeric_limits<int>::max();
    int i = 0;
    int j = 0;
    for (int k = l; k < r; k++) {
        if (left[i] <= right[j]) {
            nums[k] = left[i++];
        } else {
            nums[k] = right[j++];
        }
        compare++;
    }
}

void mergeSort(vector<int>& nums, int l, int r)
{
    if (r - l <= 1) return;
    int m = l + (r - l) / 2;
    mergeSort(nums, l, m);
    mergeSort(nums, m, r);
    merge(nums, l, m, r);
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    mergeSort(nums, 0, nums.size());
    for (int i = 0; i < nums.size(); i++) {
        if (i > 0) {
            cout << " ";
        }
        cout << nums[i];
    }
    cout << endl;
    cout << compare << endl;
}
