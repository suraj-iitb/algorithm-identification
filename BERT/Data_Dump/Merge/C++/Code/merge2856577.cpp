#include<iostream>
using namespace std;
#define INF 2<<29;
int S[500000];
int merge(int left, int mid, int right) {
	int count = 0;
	int n1 = mid - left;
	int n2 = right - mid;
	int L[n1+1], R[n2+1];
	for (int i = 0; i < n1; i++) {
		L[i] = S[left + i];
	}
	for (int i = 0; i < n2; i++) {
		R[i] = S[mid + i];
	}
	L[n1] = INF;
	R[n2] = INF;
	int i = 0;
	int j = 0;
	for (int k = left; k < right; k++) {
		count++;
		if (L[i] <= R[j]) {
			S[k] = L[i];
			i++;
		}else {
			S[k] = R[j];
			j++;
		}
	}
	return count;
}
int mergeSort(int left,int right) {
	int count = 0;
	if (left + 1 < right) {
		int mid = (left + right) / 2;
		count += mergeSort(left, mid);
		count += mergeSort(mid,right);
		count += merge(left, mid, right);
	}
	return count;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> S[i];
	}
	int count = mergeSort(0,n);
	for (int i = 0; i < n-1; i++) {
		cout << S[i] << " ";
	}
	cout << S[n - 1] << endl;
	cout << count <<endl;
	return 0;
}
