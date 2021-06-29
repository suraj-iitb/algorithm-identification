#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[500000];
int all = 0;
int b[250000], c[250000];
void merge_sort(int left, int midle, int right) {
	for (int i = 0; i < midle - left; i++) {
		b[i] = a[i + left];
	}
	for (int i = 0; i < right - midle; i++) {
		c[i] = a[i + midle];
	}
	int j = 0;
	int k = 0;
	for (int i = left; i < right; i++) {
		if (k==right-midle||(j<midle-left&& b[j]<=c[k]))
		{
			a[i] = b[j];
			j++;
		}
		else{
			a[i] = c[k];
			k++;
		}
		all++;
	}
}
void merge(int left, int right) {
	if (left+1 <right)
	{
		int mid = (left + right) / 2;
		merge(left, mid);
		merge(mid, right);
		merge_sort(left, mid, right);
	}
}
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	merge(0, n);
	for (int i = 0; i < n; i++) {
		if (i) cout << " ";
		cout << a[i];
	}
	cout << endl << all << endl;
}
