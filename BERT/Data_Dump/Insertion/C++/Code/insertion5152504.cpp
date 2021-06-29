#include <iostream>
#include <vector>

using std::cout;
using std::cin;

void Insert_sort(std::vector<int> &list,int n)
{
	int temp,j;
	for (int i = 1;i < n;i++)
	{
		temp = list[i];
		j = i - 1;
		while ((temp < list[j]) && j >= 0)
		{
			list[j + 1] = list[j];
			j--;	
		}	
		list[j + 1] = temp; 
		for(int k = 0;k < list.size() - 1;k++)
		{
			cout << list[k] << ' ';
		}
		cout << list[list.size() - 1] << std::endl;
	}	
}

int main(void)
{
	int n;
	cin >> n;
	std::vector<int> list(n);
		
	for (int i = 0; i < list.size();i++)
	{
		cin >> list[i];
	}
	
	for(int k = 0;k < list.size() - 1;k++)
	{
		cout << list[k] << ' ';
	}
	cout << list[list.size() - 1] << std::endl;
	
	Insert_sort(list,n);
	
	return 0; 
} 
