#include <iostream>
#include <vector>
using namespace std;

int bubble_sort(vector<int>& nums) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = (int)nums.size() - 1; j > i; j--) {
            if (nums[j] < nums[j - 1]) {
                swap(nums[j], nums[j - 1]);
                res++;
            }
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    int res = bubble_sort(nums);
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << nums[i];
    }
    cout << endl;
    cout << res << endl;
    return 0;
}
