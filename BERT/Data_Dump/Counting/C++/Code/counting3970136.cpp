#include<iostream>
#include<cstdio>
using namespace std;
int a[10001];
int main(void) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int key;
		cin >> key;
		a[key]++;
	}
	int adjust=0;
	for (int i = 0; i < 10001; i++) {
		while (a[i])
		{
			if (adjust) cout << " ";
			cout << i;
			a[i]--;
			adjust = 1;
		}
	}
	cout<<endl;
}
