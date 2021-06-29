#include <iostream>
#include <vector>
using namespace std;

void Insert(vector<int> vecIn, int nCount)
{
	for (int i = 1; i < nCount; i++)
	{
		int nTemp = vecIn[i];
		int j = i - 1;
		for (; j >= 0 && vecIn[j] > nTemp; --j)
		{
			vecIn[j + 1] = vecIn[j];
		}
		vecIn[j + 1] = nTemp;

		for (int i = 0; i < vecIn.size(); i++)
		{
			cout << vecIn[i];
			if (i != vecIn.size() - 1)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}


int main()
{
	int nCount = 0;
	cin >> nCount;
	vector<int> vecIn(nCount, 0);
	for (int i = 0; i < vecIn.capacity(); i++)
	{
		cin >> vecIn[i];
	}

	for (int i = 0; i < vecIn.size(); i++)
	{
		cout << vecIn[i];
		if (i != vecIn.size() - 1)
		{
			cout << " ";
		}
	}
	cout << endl;

	Insert(vecIn, nCount);
	//system("pause");
	return 0;
}
