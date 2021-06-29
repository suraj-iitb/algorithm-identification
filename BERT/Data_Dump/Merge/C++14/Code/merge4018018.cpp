#include <iostream>
#include <vector>
using namespace std;

const int INF = 1 << 30;
int S[500000];

int merge(int left, int mid, int right) {
	int n1 = mid - left;
	int n2 = right - mid;
	vector<int> L(n1+1), R(n2+1);
	for (int i = 0; i < n1; i++) L[i] = S[left+i];
	for (int i = 0; i < n2; i++) R[i] = S[mid+i];
	L[n1] = INF;
	R[n2] = INF;
	int i = 0, j = 0;
	for (int k = left; k <= right-1; k++) {
		if (L[i] <= R[j]) {
			S[k] = L[i];
			i++;
		}
		else {
			S[k] = R[j];
			j++;
		}
	}
	return right - left;
}

int mergeSort(int left, int right) {
	if (left + 1 >= right) return 0;
	int mid = (left + right) / 2;
	int ans = 0;
	ans += mergeSort(left, mid);
	ans += mergeSort(mid, right);
	ans += merge(left, mid, right);
	return ans;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> S[i];
	int ans = mergeSort(0, n);

	cout << S[0];
	for (int i = 1; i < n; i++) cout << ' ' << S[i];
	cout << endl << ans << endl;
}

