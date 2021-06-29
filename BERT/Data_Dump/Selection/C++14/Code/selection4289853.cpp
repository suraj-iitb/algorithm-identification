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
	int a[n], ans = 0;
	for(int i = 0; i < n; i++)cin >> a[i];
	for(int i = 0; i < n; i++){
		int min_ = i;
		for(int j = i; j < n; j++){
			if(a[j] < a[min_]){
				min_ = j;
			}
		}
		if(min_ != i){
			swap(a[i], a[min_]);
			ans++;
		}
	}
	
	cout << a[0];
	for(int i = 1; i < n; i++)cout << ' ' << a[i];
	cout << '\n' << ans << '\n'; 
	return 0;
}

