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
    
    int count = 0;

    bool flag = true;
    while (flag) {
        flag = false;
        for (int j = len - 1; j >= 1; j--) {
            if (nums[j] < nums[j - 1]) {
                swap(nums[j], nums[j - 1]);
                flag = true;
                count++;
            }
        }

    }

    WriteArray(nums);
    cout << count << endl;

    return 0;
}
