#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int selectionSort(vector<int> nums, int numsSize);

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++)
    {
        cin >> nums[i];
    }
    int answer = selectionSort(nums, n);
    cout << answer << endl;

    return 0;
}

int selectionSort(vector<int> nums, int numsSize)
{
    int cnt = 0;
    int tmp,mindex;
    for (int i = 0; i < numsSize; i++)
    {
        mindex = i;
        for (int j = i; j < numsSize;j++) 
        {
            if (nums[mindex]>nums[j]) 
            {
                mindex = j;
            }
        }
        if (mindex!=i)
        {
            tmp = nums[mindex];
            nums[mindex] = nums[i];
            nums[i] = tmp;
            cnt++;
        }
    }
    for (int i = 0; i < numsSize;i++)
    {
        cout << nums[i] << (i == numsSize - 1 ? '\n' : ' ');
    }
    return cnt;
}
