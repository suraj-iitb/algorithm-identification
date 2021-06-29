#include <iostream>
#include <algorithm>
using namespace std;
int a[100];
int bubbleSort(int N){
	int cnt = 0;
	bool flag = true;
	while (flag){
		flag = false;
		for (int i = N - 1; i >= 1; --i){
			if (a[i] < a[i - 1]) swap(a[i], a[i - 1]), flag=true, ++cnt;
		}
	}
	return cnt;
}
int main(){
	int n; cin >> n; 
	for (int i = 0; i < n; ++i) cin >> a[i];
	int cnt=bubbleSort(n);
	for (int i = 0; i < n; ++i){
		if (i != 0) cout << ' ';
		cout << a[i];
	}
	cout << '\n' << cnt << '\n';
}
