#include<iostream>
#include<string>
using namespace std;
const int N = 100000;

struct C
{
	string de;
	int n;
}card1[N], card2[N], L[N], R[N];

void merge(int left, int mid, int right)
{
	int n1 = mid - left;
	int n2 = right - (mid + 1);

	for (int i = 0; i <= n1; i++)
		L[i] = card1[left + i];
	for (int i = 0; i <= n2; i++)
		R[i] = card1[mid + 1 + i];

	L[n1 + 1].n = R[n2 + 1].n = (int)2e9;

	int i = 0, j = 0;
	for (int k = left; k <= right; k++)
	{
		if (L[i].n <= R[j].n)
			card1[k] = L[i++];
		else
			card1[k] = R[j++];
	}
}

void MergeSort(int left, int right)         //分治法
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(left, mid);               //先将左边分割
		MergeSort(mid + 1, right);          //再将右边分割
		merge(left, mid, right);            //排序,组合
	}
}

int partition(int p, int r)
{
	int i = p;
	C temp;

	for (int j = p; j < r; j++)
	{
		if (card2[j].n <= card2[r].n)
		{
			temp = card2[i];
			card2[i] = card2[j];
			card2[j] = temp;

			i += 1;
		}
	}
	temp = card2[i];
	card2[i] = card2[r];
	card2[r] = temp;

	return i;
}

void QuickSort(int p, int r)
{
	int q;
	if (p < r)
	{
		q = partition(p, r);
		QuickSort(p, q - 1);
		QuickSort(q + 1, r);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	bool T = true;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> card1[i].de >> card1[i].n;
		card2[i] = card1[i];
	}

	MergeSort(0, n - 1);
	QuickSort(0, n - 1);

	for (int i = 0; i < n; i++)
	{
		if (card2[i].de != card1[i].de)
			T = false;
	}

	if (T)
		cout << "Stable\n";
	else
		cout << "Not stable\n";

	for (int i = 0; i < n - 1; i++)
		cout << card2[i].de << " " << card2[i].n << endl;
	cout << card2[n - 1].de << " " << card2[n - 1].n << endl;

	return 0;
}
