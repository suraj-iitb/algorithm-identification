#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int temp,n;
	cin >> n;
	int ans[n] = {0,};
	// 计数 
	int count[10001] = {0,};
	int vec[n];
	//  
	for(int i = 0;i < n;i++)
	{
		cin >> temp;
		vec[i] = temp;
		count[temp]++;
		ans[i] = 0;
	}
	// count标准化 
	for(int i = 1;i <= 10001;i++)
	{
		count[i] = count[i] + count[i-1];	
	} 
	// 通过计数器 给ans数组赋值 
	for(int i=0;i<n;i++)
	{
		ans[count[vec[i]]-1] = vec[i];
		count[vec[i]]--;
	}
	
	for(int i=0;i<n-1;i++)
	{
		cout << ans[i] << ' ';
	}
	cout << ans[n-1] << endl;
	
	return 0;
}
