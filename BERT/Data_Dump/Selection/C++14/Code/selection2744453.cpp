#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int nNum = 0;
	int nArrIn[100] = { 0 };
	cin >> nNum;
	for (int i = 0; i < nNum; ++i)
	{
		cin >> nArrIn[i];
	}
	int nMin = 0, nCount = 0;
	for (int i = 0; i < nNum - 1; ++i)
	{
		nMin = i;
		for (int j = i + 1; j < nNum; ++j)
		{
			if (nArrIn[j] < nArrIn[nMin])
			{
				nMin = j;
			}
		}
		if (i != nMin)
		{
			swap(nArrIn[i], nArrIn[nMin]);
			++nCount;
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
