// 失敗するからこそ そこから立ち向かって行く強さがあってそんな強さが本当の強さだと私は思うから
// ぜったいあきらめない
#include<bits/stdc++.h>
using namespace std;

#if defined(DAIJOBU)
#include "/home/ichigo/debug.hpp"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif
#define FIO {ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);}
	

int main(){
	FIO
	
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)cin >> a[i];
	cout << a[0];
	for(int i = 1; i < n; i++)cout << ' ' << a[i];
	cout << '\n';
	for(int i = 1; i < n; i++){
		int key = a[i];
		int j = i - 1;
		while(j >= 0 && a[j] >= key){
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
		cout << a[0];
		for(int i = 1; i < n; i++)cout << ' ' << a[i];
		cout << '\n';
	}
	
	return 0;
}

