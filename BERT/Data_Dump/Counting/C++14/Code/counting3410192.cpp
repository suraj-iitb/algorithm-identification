#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

//#define MAX 2000001
#define CMAX 10000
int main()
{
	int nIn = 0;
	cin >> nIn;

	int *nA = new int[nIn];
	int *nB = new int[nIn];
	int nC[CMAX + 1] = { 0 };
	for (int i = 0; i < nIn; ++i)
	{
		cin >> nA[i];
		++nC[nA[i]];
		//nB[i] = nA[i];
	}

	for (int j = 1; j <= CMAX; ++j)
	{
		nC[j] = nC[j] + nC[j - 1];
	}

	for (int j = nIn - 1; j >= 0; --j)
	{
		nB[nC[nA[j]]] = nA[j];
		nC[nA[j]]--;
	}

	for (int i = 1; i <= nIn; ++i)
	{
		if (i > 1)
		{
			cout << " ";
		}
		cout << nB[i];
	}
	cout << endl;
	//system("pause");
	return 0;
}
