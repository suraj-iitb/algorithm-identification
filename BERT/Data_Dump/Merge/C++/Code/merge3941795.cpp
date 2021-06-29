#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>

using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
typedef long long ll;
typedef unsigned long long ull;

int cnt = 0;
int S[500000];

void merge(int* A, int left, int mid, int right)
{
	int i = 0, j = 0;

	int n1 = mid - left;
	int n2 = right - mid;

	int* L = new int[n1 + 1];
	int* R = new int[n2 + 1];

	rep(i, n1) L[i] = A[left + i];
	rep(i, n2) R[i] = A[mid + i];
	L[n1] = 1000000001;
	R[n2] = 1000000001;

	rep1(k, left, right - 1) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else {
			A[k] = R[j];
			j++;
		}
		cnt++;
	}

	delete[] L, R;
}

void mergeSort(int* A, int left, int right)
{
	int mid;

	if (left + 1 < right) {
		mid = (left + right) / 2;
		mergeSort(A, left, mid);
		mergeSort(A, mid, right);
		merge(A, left, mid, right);
	}
}

int main()
{
	int N;

	cin >> N;
	rep(i, N) cin >> S[i];

	mergeSort(S, 0, N);

	cout << S[0];
	rep1(i, 1, N - 1) cout << ' ' << S[i];
	cout << endl << cnt << endl;

	return 0;
}

