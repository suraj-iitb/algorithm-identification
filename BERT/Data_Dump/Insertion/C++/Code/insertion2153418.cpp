#include <iostream>
using namespace std;

void show(int nums[], int n) {
    for (int k = 0; k < n; ++k) {
        if( k == n - 1) {
            cout << nums[k];
        } else {
            cout << nums[k] << " ";
        }
    }
    cout << endl;
}

void insert_sort(int nums[], int n) {
    for (int i = 1; i < n; ++i) {
        int v = nums[i];
        int j = i - 1;
        while (j >= 0 && nums[j] > v) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = v;
        show(nums, n);
    }
}

int main()
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    show(nums, n);
    insert_sort(nums, n);
    return 0;
}
