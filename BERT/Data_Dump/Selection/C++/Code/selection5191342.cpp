#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int* p = new int[n];
	int i, j, num = 0;
	for (i = 0;i < n;i++)
		cin >> p[i];
	for (i = 0;i < n;i++) {
		int k = i;
		for (j = i;j < n;j++) {
			if (p[j] < p[k]) {
				k = j;
			}
		}
		if (p[i] > p[k]) {
			int temp = p[i];
			p[i] = p[k];
			p[k] = temp;
			num++;
		}
	}
	for (i = 0;i < n-1;i++)
		cout << p[i]<<" ";
	cout << p[n-1] << endl;
	cout << num << endl;
	return 0;
}
