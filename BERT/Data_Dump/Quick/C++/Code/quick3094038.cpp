#include<iostream>
#include<algorithm>
using namespace std;
int partition(pair<char, int> A[], int left, int right)
{
	pair<char, int> base = A[right];
	int i = left - 1;
	for (int j = left; j < right; j++)
		if (A[j].second <= base.second)
		{
			i++;
			swap(A[i], A[j]);
		}
	swap(A[i + 1], A[right]);
	return i + 1;
}

void quickSort(pair<char, int> A[], int left, int right)
{
	if (left >= right)
		return;
	int idx = partition(A, left, right);
	quickSort(A, left, idx - 1);
	quickSort(A, idx + 1, right);
}
void merge(pair<char, int> A[], int left, int mid, int right)
{
	const int INF = 999999999;
	int ln = mid - left + 1;
	int rn = right - mid;
	pair<char, int> *L = new pair<char, int>[ln + 1];
	pair<char, int> *R = new pair<char, int>[rn + 1];
	for (int i = 0; i < ln; i++)
		L[i] = A[left + i];
	for (int i = 0; i < rn; i++)
		R[i] = A[mid + 1 + i];
	L[ln].second = R[rn].second = INF;
	int i = 0, j = 0;
	for (int k = left; k <= right; k++)
		if (L[i].second <= R[j].second)
			A[k] = L[i++];
		else
			A[k] = R[j++];
	delete[] L;
	delete[] R;
}
void mergeSort(pair<char, int> A[], int left, int right)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	mergeSort(A, left, mid);
	mergeSort(A, mid + 1, right);
	merge(A, left, mid, right);
}
bool isStable(pair<char, int> A[], pair<char, int> B[], int n)
{
	for (int i = 0; i < n; i++)
		if (A[i].first != B[i].first)
			return false;
	return true;
}
int main()
{
	int n;
	cin >> n;
	pair<char, int> *card1 = new pair<char, int>[n];
	pair<char, int> *card2 = new pair<char, int>[n];
	for (int i = 0; i < n; i++)
	{
		cin >> card1[i].first >> card1[i].second;
		card2[i].first = card1[i].first;
		card2[i].second = card1[i].second;
	}
	quickSort(card1, 0, n - 1);
	mergeSort(card2, 0, n - 1);
	cout << (isStable(card1, card2, n) ? "Stable" : "Not stable") << endl;
	for (int i = 0; i < n; i++)
		cout << card1[i].first << " " << card1[i].second << endl;
}
