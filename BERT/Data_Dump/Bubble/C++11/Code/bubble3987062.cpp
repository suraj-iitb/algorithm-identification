//bubble sort
//in ascending order
//return value: swapping times
#include <iostream>
#include <algorithm>
#define max_n 101
using namespace std;

//ver1.0 with flag
int bubbleSort(int* a, int n)
{
	int cnt_sw = 0;
	bool flag = 1;
	
	while(flag)
	{
		flag = 0;
		for(int j = 0; j < n - 1; j++)
		{
			if(a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				
				++cnt_sw;
				flag = 1;	
			}				
		}
	}
	return cnt_sw;
}

//ver2.0 with flag & remark
//±ê¼ÇÁËÉÏÒ»´ÎÅÅÐòÍêÓÐÐòµÄÏÂ±ê£¬ÊÇÕë¶ÔÃ°ÅÝÅÅÐòµÄÌØÖÆÓÅ»¯ 
int bubbleSort_(int* a, int n)
{
	int cnt_sw = 0;
	int mem = n - 1;
	bool flag = 1;
	
	while(flag)
	{
		flag = 0;
		for(int j = 0; j < mem; ++j)
		{
			if(a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				
				++cnt_sw;
				flag = 1;	
			}				
		}
		--mem;
	}
	return cnt_sw;
} 
 
int main(void)
{
	int n, a[max_n];
	
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
		
	int ans = bubbleSort_(a, n);
	for(int i = 0; i < n; ++i)
	{
		if(i)
			cout << " ";
		cout << a[i];
	}
	cout << endl;
	cout << ans << endl;
	
	return 0;
}
