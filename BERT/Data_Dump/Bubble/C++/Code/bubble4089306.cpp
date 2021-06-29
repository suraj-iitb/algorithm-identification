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

	bool flag = true;
	int counter = 0;
	for (int i = 0; flag; ++i)
	{
		flag = false;
		for (int j = number - 1; j >= i+1; --j)
		{
			if (array[j] < array[j - 1])
			{
				swap(array[j], array[j - 1]);
				flag = true;
				++counter;
			}
		}
	}

	outputArray(array);

	cout << counter << endl;

	return 0;
}
