#include <iostream>

using namespace std;

void WriteArray(int* nums, int length) {
    for (int i = 0; i < length; i++) {
        cout << nums[i];
        if (i < length - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    int n;
    int nums[100];
    string s;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> nums[i];
    
    WriteArray(nums, n);

    for (int i = 1; i < n; i++) {
        int v = nums[i];
        int j = i - 1;
        for (; j >= 0 && nums[j] > v; j--) {
            nums[j + 1] = nums[j];
        }
        nums[j + 1] = v;

        WriteArray(nums, n);
    }

    return 0;
}
