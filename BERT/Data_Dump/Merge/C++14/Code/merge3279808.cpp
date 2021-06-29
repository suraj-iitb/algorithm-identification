#include <iostream>
using namespace std;
#define MAX 500000
#define SENTINEL 1000000001
int nC;

void merge_sort(int nA[], int nLeft, int nMid, int nRight)
{
	int n1 = nMid - nLeft, n2 = nRight - nMid;

	int nL[MAX / 2 + 1], nR[MAX / 2 + 1];
	for (int i = 0; i < n1; i++)
	{
		nL[i] = nA[nLeft + i];
	}
	for (int i = 0; i < n2; i++)
	{
		nR[i] = nA[nMid + i];
	}
	nL[n1] = SENTINEL;
	nR[n2] = SENTINEL;
	int i = 0, j = 0;
	for (int k = nLeft; k < nRight; k++)
	{
		nC++;
		if (nL[i] <= nR[j])
		{
			nA[k] = nL[i++];
		}
		else
		{
			nA[k] = nR[j++];
		}
	}
}

void merge(int nA[], int nLeft, int nRight)
{
	int nMid = 0;
	if (nLeft + 1 < nRight)
	{
		nMid = (nLeft + nRight) / 2;
		merge(nA, nLeft, nMid);
		merge(nA, nMid, nRight);
		merge_sort(nA, nLeft, nMid, nRight);
	}
}

int main()
{
	int nIn;
	nC = 0;
	cin >> nIn;
	int nA[MAX];
	for (int i = 0; i < nIn; i++)
	{
		cin >> nA[i];
	}
	merge(nA, 0, nIn);
	for (int i = 0; i < nIn; i++)
	{
		if (i)
		{
			cout << " ";
		}
		cout << nA[i];
	}
	cout << endl << nC << endl;
	//system("pause");
}
