#include <iostream>
#include <vector>
using namespace std;
void insertionSort(vector<int> nums, int numsSize);

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n;i++)
    {
        cin >> nums[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << (i == n - 1 ? '\n' : ' ');
    }
    insertionSort(nums, n);

    return 0;
}

void insertionSort(vector<int> nums, int numsSize)
{
    int num, j;
    for (int i = 1; i < numsSize; i++)
    {
        num = nums[i];
        j = i - 1;
        while (j >= 0 && nums[j] > num)
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j+1] = num;
        for (int k = 0; k < numsSize; k++)
        {
            cout << nums[k] << (k==numsSize-1?'\n':' ');
        }
        
    }
}
