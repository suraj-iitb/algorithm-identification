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

void bubble_sort(int nums[], int n) {
    int flag = 1;
    int count = 0;
    while(flag) {
        flag = 0;
        for (int i = n - 1; i >= 1 ; --i) {
           if(nums[i] < nums[i - 1]) {
               int temp = nums[i];
               nums[i] = nums[i - 1];
               nums[i - 1] = temp;
               flag = 1;
               count++;
           }
        }
    }
    show(nums, n);
    cout << count << endl;
}

int main()
{
    int n;
    cin >> n;
    int nums[n];
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    bubble_sort(nums, n);
    return 0;
}
