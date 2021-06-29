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

typedef long long llong;
const int MAX = 100010;
const int INFTY = 1000000001;
vector<pair<char, int> > card, card_merge;

int partition(int left, int right, int n)
{
	int i, j;
	pair<char, int> x;
	x = card[right];
	i = left - 1;
	for (j = left; j < right; j++) {
		if (card[j].second <= x.second) {
			i++;
			swap(card[i], card[j]);
		}
	}
	swap(card[i + 1], card[right]);
	return i + 1;
}

void quickSort(int left, int right, int n)
{
	if (left < right) {
		int k = partition(left, right, n);
		quickSort(left, k - 1, n);
		quickSort(k + 1, right, n);
	}
}

void merge(int left, int mid, int right)
{
	int n1 = mid - left, n2 = right - mid;
	vector<pair<char,int> >L(n1 + 1), R(n2 + 1);
	for (int i = 0; i < n1; i++)
		L[i] = card_merge[left + i];
	for (int i = 0; i < n2; i++)
		R[i] = card_merge[mid + i];
	L[n1].second = R[n2].second = INFTY;
	int i = 0, j = 0;
	for (int k = left; k < right; k++) {
		if (L[i].second <= R[j].second) {
			card_merge[k] = L[i];
			i += 1;
		}
		else {
			card_merge[k] = R[j];
			j += 1;
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
	int n, num;
	char C;
	bool ok = true;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> C >> num;
		card.push_back(make_pair(C, num));
		card_merge.push_back(make_pair(C, num));
	}
	quickSort(0, n - 1, n);
	mergeSort(0, n);
	for (int i = 0; i < n; i++) {
		if (card[i] != card_merge[i]) {
			ok = false;
			break;
		}
	}
	if (ok)
		cout << "Stable" << endl;
	else
		cout << "Not stable" << endl;
	for (int i = 0; i < n; i++)
		cout << card[i].first << " " << card[i].second << endl;
	return 0;
}





