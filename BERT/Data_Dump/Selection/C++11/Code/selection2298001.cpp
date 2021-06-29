#include <iostream>
#include <vector>

using namespace std;

void WriteArray(const vector<int>& nums) {
    for (auto iterator = nums.begin(); iterator != nums.end(); ++iterator) {
        cout << *iterator << (iterator + 1 != nums.end() ? " " : "");
    }
    cout << endl;
}

int main() {
    int len;
    cin >> len;
    vector<int> nums(len);

    for (int i = 0; i < len; i++) cin >> nums[i];

    int swapCount = 0;

    for (int i = 0; i < nums.size(); ++i) {
        int minj = i;
        for (int j = i; j < nums.size(); ++j) {
            if (nums[j] < nums[minj]) minj = j;
        }
        if (i != minj) {
            swap(nums[i], nums[minj]);
            swapCount++;
        }
    }

    WriteArray(nums);
    cout << swapCount << endl;

    return 0;
}
