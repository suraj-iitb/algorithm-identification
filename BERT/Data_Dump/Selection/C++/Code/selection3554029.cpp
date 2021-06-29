#include <iostream>
#include <vector>
using namespace std;

int selection_sort(vector<int>& nums) {
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++) {
        int mini = i;
        for (int j = i; j < nums.size(); j++) {
            if (nums[j] < nums[mini])
                mini = j;
        }
        swap(nums[i], nums[mini]);
        if (i != mini)
            cnt++;
    }
    return cnt;
}

int main() {
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    int cnt = selection_sort(nums);
    for (int i = 0; i < N; i++) {
        if (i > 0)
            cout << " ";
        cout << nums[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
