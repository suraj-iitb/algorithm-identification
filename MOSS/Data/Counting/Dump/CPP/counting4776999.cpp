#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	vector<int> nums(10001, 0);
	int n; scanf("%d",&n);
	for(int i = 0; i < n; ++i) {
		int x; scanf("%d",&x);
		++nums[x];
	}
	bool first = true;
	for(unsigned int i = 0; i < nums.size(); ++i) {
		for(int j = 1; j <= nums[i]; ++j) {
			if(first) {
				first = false;
			} else {
				putchar(' ');
			}
			printf("%d",i);
		}
	} putchar('\n');
	return 0;
}

