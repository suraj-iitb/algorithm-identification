#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int numberAmount;
	cin >> numberAmount;
	vector<int> numberVector;
	int maxNumber = 0;
	for (int i = 0; i != numberAmount; ++i)
	{
		int number;
		cin >> number;
		maxNumber = number > maxNumber ? number : maxNumber;
		numberVector.push_back(number);
	}
	vector<int> numberBucket(maxNumber + 1,0);
	for (int i = 0; i < numberAmount; ++i)
	{
		++numberBucket[numberVector[i]];
	}
	bool firstIn = true;
	for (int i = 0; i <= maxNumber; ++i)
	{
		for (int j = 0; j < numberBucket[i]; ++j)
		{
			if (firstIn)
			{
				firstIn = false;
			}
			else
			{
				cout << " ";
			}
			cout << i;
			
		}
	}
	cout << endl;
}
