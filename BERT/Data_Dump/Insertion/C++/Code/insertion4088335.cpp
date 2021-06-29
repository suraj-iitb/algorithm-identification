#include<iostream>
#include<vector>

using namespace std;

void outputArray(vector<int> array)
{
	for (int i = 0; i != array.size(); ++i)
	{
		cout << array[i];
		if (i + 1 != array.size())
			cout << " ";
	}
	cout << endl;
}

int main()
{
	int num = 0;
	cin >> num;

	vector<int> array(num);
	for (int i = 0; i != num; ++i)
	{
		cin >> array[i];
	}

	outputArray(array);

	for (int i = 1; i != num; ++i)
	{
		int v = array[i];
		int j;
		for (j = i - 1; j >= 0; --j)
		{
			if (array[j] > v)
			{
				array[j + 1] = array[j];
			}
			else
				break;
		}
		array[j + 1] = v;
		outputArray(array);
	}

	return 0;
}
