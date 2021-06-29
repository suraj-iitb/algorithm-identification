#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int*, int);

int ans = 0;

int main(void){
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	bubbleSort(a, n);
	
	for(int i=0; i<n-1; i++){
		cout << a[i] << " ";
	}
	cout << a[n-1] << endl;
	cout << ans << endl;
	return 0;
}

void bubbleSort(int* a, int n){
	bool flg = 1;
	while(flg){
		flg = 0;
		for(int j = n-1; j >=1; j--){
			if(a[j] < a[j-1]){
				int bf = a[j];
				a[j] = a[j-1];
				a[j-1] = bf;
				flg = 1;
				ans++;
			}
		}
	}
	return;
}
