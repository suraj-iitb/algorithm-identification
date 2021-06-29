#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, c = 0;
	cin >> n;
	int a[n];
	for (int i=0;i<n;i++) cin >> a[i];
	for (int i=0;i<n;i++){
		for (int j=n - 1;j>i;j--){
			if (a[j] < a[j - 1]){
				swap(a[j], a[j - 1]);
				c++;
			}
		}
	}
	for (int i=0;i<n;i++){
		cout << a[i];
		if (i == n - 1) break;
		cout << ' ';
	}
	cout << endl;
	cout << c << endl;
}
