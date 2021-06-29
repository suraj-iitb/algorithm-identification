#include"bits/stdc++.h"
using namespace std;

#define MAX 2000000000

void print(vector<int>& S)
{
	for (int i = 0; i < S.size(); i++)
	{
		if (i) cout << " ";
		cout << S.at(i);
	}
	cout << endl;
	return;
}

int merge(vector<int>& S, int left, int mid, int right)
{
	int n1 = (mid - left);
	int n2 = (right - mid);

	vector<int> L(n1), R(n2);
	for (int i = 0; i < n1; i++) L.at(i) = S.at(left + i);
	for (int i = 0; i < n2; i++) R.at(i) = S.at(mid + i);
	L.push_back(MAX);
	R.push_back(MAX);

	int i = 0;
	int j = 0;
	for (int k = left; k < right; k++)
	{
		if (L.at(i) <= R.at(j))
		{
			S.at(k) = L.at(i);
			i++;
		}
		else {
			S.at(k) = R.at(j);
			j++;
		}
	}

	return (i + j);
}

int mergeSort(vector<int>& S, int left, int right)
{
	if (left + 1 >= right) return 0;

	int ans = 0;

	int mid = (left + right) / 2;
	ans += mergeSort(S, left, mid);
	ans += mergeSort(S, mid, right);
	ans += merge(S, left, mid, right);

	return ans;
}

int main(void) {

	int N, ans;
	cin >> N;
	vector<int> S(N);
	for (int i = 0; i < N; i++) cin >> S.at(i);

	ans = mergeSort(S, 0, N);

	print(S);
	cout << ans << endl;

	return 0;
}

