#include <iostream>
using namespace std;

int main()
{
	int nNum = 0;
	cin >> nNum;
	int nArrIn[100] = { 0 };
	for (int i = 0; i < nNum; ++i)
	{
		cin >> nArrIn[i];
	}
	//Bubble
	int nCount = 0;
	for (int i = 0; i < nNum - 1; ++i)
	{
		for (int j = nNum - 1; j >= i + 1; --j)
		{
			if (nArrIn[j] < nArrIn[j - 1])
			{
				swap(nArrIn[j - 1], nArrIn[j]);
				++nCount;
			}
		}
	}
	for (int i = 0; i < nNum - 1; ++i)
	{
		cout << nArrIn[i] << " ";
	}
	cout << nArrIn[nNum - 1] << endl;
	cout << nCount << endl;
	return 0;
}
