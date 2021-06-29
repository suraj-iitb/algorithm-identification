#include <iostream>
#include <vector>
using namespace std;
int bubbleSort(vector<int> nums, int numsSize);
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++)
    {
        cin >> nums[i];
    }
    int answer = bubbleSort(nums, n);
    cout << answer << endl;

    return 0;
}


int bubbleSort(vector<int> nums, int numsSize)
{
    int flag = 1, cnt = 0;
    int tmp;
    while (flag) 
    {
        flag = 0;
        for (int j = numsSize - 1; j >= 1;j--) 
        {
            if (nums[j]<nums[j-1])
            {
                tmp = nums[j];
                nums[j] = nums[j - 1];
                nums[j - 1] = tmp;
                cnt++;
                flag = 1;
            }
        }
    }
    for (int i = 0; i < numsSize;i++)
    {
        cout << nums[i] << (i == numsSize - 1 ? '\n' : ' ');
    }
        return cnt;
}
