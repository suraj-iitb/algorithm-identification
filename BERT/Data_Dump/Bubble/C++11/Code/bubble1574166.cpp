#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int a[110];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}

	int cnt = 0;
	bool flag = true;
	while(flag){
		flag = false;
		for(int i = n - 1; i >= 1; --i){
			if(a[i] < a[i - 1]){
				++ cnt;
				swap(a[i], a[i - 1]);
				flag = true;
			}
		}
	}

	for(int i = 0; i < n; ++i){
		cout << a[i];
		if(i != n - 1)
			cout << " ";
		else
			cout << endl;
	}
	cout << cnt << endl;

	return 0;
}
