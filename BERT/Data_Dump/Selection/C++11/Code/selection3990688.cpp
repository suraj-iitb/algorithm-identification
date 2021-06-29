//selection sort
#include <iostream>
#include <algorithm>
#include <cstring>
#define max_n 101 
using namespace std;

int selectionSort(int* a, int n)
{
	int ans = 0, ind_min;
	
	for(int i = 0; i < n - 1; ++i)
	{
		ind_min = i;
		for(int j = i; j < n; ++j)
		{
			if(a[j] < a[ind_min])
				ind_min = j;	
		}	
	
	swap(a[i], a[ind_min]);
	if(ind_min != i)        //Èç¹û×îÐ¡ÏÂ±êÓÐ±ä»¯ËµÃ÷²úÉúÁËÊµ¼ÊµÄ½»»»£¬¼ÆÊýÆ÷+1 
		ans++;
	}	
	
	return ans;
}

int main(void)
{
	int a[max_n], n, res;
	
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	res = selectionSort(a, n);
	for(int i = 0; i < n; ++i)
	{
		if(i > 0)
			cout << " ";
		cout << a[i];
	}
	cout << endl;
	cout << res << endl;	
}
