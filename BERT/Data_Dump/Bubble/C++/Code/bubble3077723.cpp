#include<bits/stdc++.h>
using namespace std;
int main(void){
	int n;
	cin >> n;
	int d[n];
	for(int i = 0; i < n; i++) cin >> d[i];
	int flg = 1, cnt = 0;
	while(flg){
		flg = 0;
		for(int i = n - 1; i > 0; i--){
			if(d[i] < d[i - 1]){
				swap(d[i], d[i - 1]);
				cnt++;
				flg = 1;
			}
		}
	}
	for(int i = 0; i < n - 1; i++) cout << d[i] << ' ';
	cout << d[n - 1] << endl;
	cout << cnt << endl;
	return 0;
}
