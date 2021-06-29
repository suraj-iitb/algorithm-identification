#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int num = 0;

void Selection_sort(std::vector<int> &list,int n)
{
	int sp,temp,j;
	
	for(int i = 0;i < n-1;i++ )
	{
		sp = i;
		for(j = i;j <= n-1;j++)
		{
			if(list[j] < list[sp]) sp = j;	
		}	
		
		if(sp != i)
		{
			temp = list[i];
			list[i] = list[sp];
			list[sp] = temp;
			num++;	
		} 
	}	
} 

int main(void)
{
	int n;
	cin >> n;
	std::vector<int> list(n);
	
	std::vector<int>::iterator it;
	
	for (it = list.begin();it < list.end();it++)
	{
		cin >> *it;
	}
	
	Selection_sort(list,n);
 
	for(it = list.begin();it < list.end() - 1;it++)
	{			
		cout << *it << ' ';
	}
	cout << list[list.size() - 1] << endl;

	cout << num << endl;
	
	return 0; 
} 
