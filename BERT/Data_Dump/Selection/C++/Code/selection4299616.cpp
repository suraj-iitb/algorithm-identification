#if 1
#include<iostream>
using namespace std;
void SelectionSort(int a[], int n ,int &sum) {
	int i, j, min;
	for ( i = 0; i < n-1; i++) {
		//第一层循环为无序区
		min = i;//k记录当前的下标，到时需要交换
		for ( j = i + 1; j < n; j++) {
			//第二层循环为有序区
			if (a[j] < a[min])
				min = j; //此时min便是最小的数
		}
		if (min != i) {
			//为了防止最小数有两个，即最外层for循环i是最小数，无序区也有一个最小数，这样交换过来排序便不再稳定
			swap(a[min], a[i]);
			sum++;
		}
	}
}
void Print(int a[], int n) {
	for (int i = 0; i < n; i++) {
		if (i > 0) cout << " ";
		cout << a[i];
	}
}
int main() {
	int n, sum = 0;
	cin >> n;
	int a[105];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	SelectionSort(a, n, sum);
	Print(a, n);
	cout << endl << sum << endl;
}
#endif


