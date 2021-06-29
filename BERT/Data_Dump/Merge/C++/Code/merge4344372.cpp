#include<iostream>
using namespace std;
int a[500005];
int tmp[500005];
int  n, cnt;
void Solve(int a[],int l ,int mid ,int r , int tmp[]) {
	//合并，使用三个指针指向三个数组
	int p = 0;
	int p1 = l, p2 = mid + 1;
	while (p1 <= mid && p2 <= r) {
		cnt++;
		if (a[p1] <= a[p2])
			tmp[p++] = a[p1++]; 
		else
			tmp[p++] = a[p2++];
	}
	while (p1 <= mid) {
		cnt++;
		tmp[p++] = a[p1++];
	}
	while (p2 <= r) {
		cnt++;
		tmp[p++] = a[p2++];
	}
	for (int i = 0; i <r-l+1; i++) {
		a[l+i] = tmp[i];
	}
}
void MerageSort(int a[] ,int l ,int r ,int tmp[]) {
	if (l < r) {
		int mid = l + (r - l) / 2;
		MerageSort(a, l, mid, tmp);
		MerageSort(a, mid + 1, r, tmp);
		Solve(a, l, mid, r, tmp);//合并函数
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	MerageSort(a, 0, n - 1, tmp);
	for (int i = 0; i < n; i++) {
		if (i) cout << " ";
		cout << a[i];
	}
	cout << endl << cnt << endl;
}
