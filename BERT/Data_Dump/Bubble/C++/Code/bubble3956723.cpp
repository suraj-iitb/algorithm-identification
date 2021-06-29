#include<iostream>
#include<algorithm>
using namespace std;
int sort_1(int a[], int n) {
	int k = 0;
	for (int i = n; i > 0; i--)
	{
		int flag = false;
		for (int j = 0; j < i-1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
				flag = true;
				k++;
			}
		}
		if (!flag) break;
	}
	return k;
}
int main(void) {
	int n;
	cin >> n;
	int a[100];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k = sort_1(a, n);
	for (int i = 0; i < n; i++) {
	    if(i>0) cout<<" ";
		cout << a[i];
	}
	cout << endl << k<<endl;
}
