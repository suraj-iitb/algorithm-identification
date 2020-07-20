#include <iostream>
#include <vector>
using namespace std;

void swap(int &x, int &y) {
    int tmp = y;
    y = x;
    x = tmp;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums;
    for(int i=0; i<n; ++i) {
        int x;
        cin >> x;
        nums.push_back(x);
    }

    bool flag = true;
    int count = 0;
    int index = 0;
    while(flag) {
        flag = false;
        for(int i=n-1; i>index; --i) {
            if(nums[i-1] > nums[i]) {
                swap(nums[i-1], nums[i]);
                count++;
                flag = true;
            }
        }
        index++;
    }
    for(int i=0; i<n-1; ++i) {
        cout << nums[i] << " ";
    }
    cout << nums[n-1] << endl;
    cout << count << endl;

    return 0;
}
