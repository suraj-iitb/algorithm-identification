
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;

int bubbleSort(vector<int>& nums){
	int n = nums.size();
	int cnt = 0;
	for(int i = 0; i < n; i++){
		int j = n-1;
		while(j > i){
			if(nums[j] < nums[j-1]){
				 swap(nums[j], nums[j-1]);
				 cnt++;
			}
			j--;
		}		
	}
	return cnt;
}

int main(){
	int n;
	cin >> n;
	vector<int> nums(n);
	for(int i = 0; i < n; i++){
		cin >> nums[i];
	}
	int swapCnt = bubbleSort(nums);
	for(int i = 0; i < n; i++){
		if(i) cout << " " << nums[i];
		else cout << nums[i];
	}
	cout << endl;
	cout << swapCnt << endl;
	return 0;
}
