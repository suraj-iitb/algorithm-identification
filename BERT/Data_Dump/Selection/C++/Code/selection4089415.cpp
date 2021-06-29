#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void outputArray(vector<int> array)
{
	for (int i = 0; i != array.size(); ++i)
	{
		cout << array[i];
		if (i + 1 != array.size())
		{
			cout << " ";
		}
	}
	cout << endl;
}

int main()
{
	int number;
	cin >> number;

	vector<int> array(number);
	for (int i = 0; i != number; ++i)
	{
		cin >> array[i];
	}

	int count = 0;
	for (int i = 0; i != number; ++i)
	{
		int minJ = i;
		for (int j = i+1; j != number; ++j)
		{
			if (array[minJ] > array[j])
			{
				minJ = j;
			}
		}
		if (minJ != i)
		{
			swap(array[minJ], array[i]);
			//outputArray(array);
			++count;
		}
	}
	

	outputArray(array);
	cout << count << endl;

	return 0;
}
