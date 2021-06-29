#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	int a[1001];
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	for (int i =0 ; i < n; ++i){
		
		int v = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > v){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = v;
		for (int i2 = 0; i2 < n; i2++){
			if (i2 == n - 1)cout << a[i2] << endl;
			else cout << a[i2]<<" ";
		}
	}
}
