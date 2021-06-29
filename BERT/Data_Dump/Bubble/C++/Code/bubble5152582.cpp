#include <iostream>
#include <vector>


using std::cin;
using std::cout;
using std::endl;

int num = 0; 
void Bubble_sort(std::vector<int> &list,std::vector<int>::iterator it,int n)
{
	int temp,j;
	for(int i = 0;i < n-1;i++) // 进行n-1次就行 
	{
		j = n - 1;
		while(j > i) // 保证不越界 
		{
			if(list[j-1] > list[j])
			{
				temp = list[j - 1];
				list[j - 1] = list[j];
				list[j] = temp;
				num++;
				j--;
			}
			else
			{
				j--;
			}
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
	
	Bubble_sort(list,it,n);
 
	for(it = list.begin();it < list.end() - 1;it++)
	{			
		cout << *it << ' ';
	}
	cout << list[list.size() - 1] << endl;

	cout << num << endl;
	
	return 0; 
} 
