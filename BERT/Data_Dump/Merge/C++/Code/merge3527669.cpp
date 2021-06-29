#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cstdio>
//#include<cmath>
using namespace std;

const int INFTY = 1000000001;
int S[500010], n, cmp;

void merge(int left, int mid, int right)
{
	int n1 = mid - left, n2 = right - mid;
	vector<int>L(n1 + 1), R(n2 + 1);
	for (int i = 0; i < n1; i++)
		L[i] = S[left + i];
	for (int i = 0; i < n2; i++)
		R[i] = S[mid + i];
	L[n1] = R[n2] = INFTY;
	int i = 0, j = 0;
	for (int k = left; k < right; k++) {
		if (L[i] <= R[j]) {
			S[k] = L[i];
			i += 1;
			cmp++;
		}
		else {
			S[k] = R[j];
			j += 1;
			cmp++;
		}
	}
}

void mergeSort(int left, int right)
{
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		mergeSort(left, mid);
		mergeSort(mid, right);
		merge(left, mid, right);
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> S[i];
	mergeSort(0, n);
	int i = 0;
	for (int j = 0; j < n; j++) {
		if (i++)
			cout << " ";
		cout << S[j];
	}
	cout << endl;
	cout << cmp << endl;
	return 0;
}
