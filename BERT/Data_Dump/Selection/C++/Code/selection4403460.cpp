#include <bits/stdc++.h>
using namespace std;
int selectSort(int *num,int n) {
	int cnt = 0;
	int minnum = 0;
	for (int i = 0; i < n; i++) {
		minnum = i;
		for (int j = i; j < n; j++) {
			if (num[minnum] > num[j]) {
				minnum = j;
			}
		}
		if (num[minnum] != num[i]) {
			swap(num[minnum], num[i]);
			cnt++;
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
	
	ans=selectSort(num,n);

	cout << endl<<ans << endl;

	return 0;
}

