#include <cstdio>
#include <vector>
using namespace std;

int SelectSort(vector<int>& nums)
{
	int cnt = 0;
	for(unsigned int i = 0; i < nums.size()-1; ++i) {
		unsigned int k = i;
		for(unsigned int j = i+1; j < nums.size(); ++j) {
			if(nums[j] < nums[k]) {
				k = j;
			}
		}
		if(k != i) {
			int t = nums[k]; nums[k] = nums[i]; nums[i] = t;
			++cnt;
		}
	}
	return cnt;
}

int main()
{
	int n; scanf("%d",&n);
	vector<int> nums(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d",&nums[i]);
	}
	int cnt = SelectSort(nums);
	for(int i = 0; i < n; ++i) {
		if(i) {
			putchar(' '); 
		}
		printf("%d",nums[i]);
	}
	putchar('\n');
	printf("%d\n",cnt);
	return 0;
}

