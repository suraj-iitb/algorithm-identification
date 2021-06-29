
#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n < 1)return 1;
	int nums[100];

	for (int i{ 0 }; i != n; i++) {
		cin >> nums[i];
	}

	for (int i{ 0 }; i != n; i++) {
		for (int j = i; j > 0 && nums[j - 1] > nums[j]; j--) {
			int temp = nums[j];
			nums[j] = nums[j - 1];
			nums[j - 1] = temp;
		}

		for (int k{ 0 }; k != n - 1; k++) {
			cout << nums[k] << ' ';
		}
		cout << nums[n - 1] << endl;
	}

	return 0;

}
