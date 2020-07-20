#include <bits/stdc++.h>
using namespace std;
int bubbleSort(int *num,int n) {
	int cnt = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (num[j] > num[j + 1]) {
				swap(num[j], num[j + 1]);
				cnt++;
			}
		}

		
	}
	for (int i = 0; i < n; i++) {
		
		cout << num[i];
		if(i!=n-1)
			cout << " ";
	}
		
	return cnt;
}

int main() {
	int ans = 0;
	int n;
	int tmp;
	int *num;
	cin >> n;
	num = new int[n];
	for (int i = 0; i < n; i++) {
		cin>>num[i];
	}
	
	ans=bubbleSort(num,n);

	cout << endl<<ans << endl;

	return 0;
}

