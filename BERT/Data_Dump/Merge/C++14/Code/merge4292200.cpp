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
int ans = 0;
void Merge(int a[], int left, int mid, int right){
	int siz1 = mid - left;
	int siz2 = right - mid;
	int L[siz1 + 1], R[siz2 + 1];
	for(int i = 0; i < siz1; i++)L[i] = a[i + left];
	for(int i = 0; i < siz2; i++)R[i] = a[i + mid];
	L[siz1] = R[siz2] = INT_MAX;
	int i = 0, j = 0;
	for(int k = left; k < right; k++){
		if(L[i] <= R[j]){
			a[k] = L[i++];
		}else{
			a[k] = R[j++];
		}
		ans++;
	}
}

void MergeSort(int a[], int left, int right){
	if(left + 1 < right){
		int mid = (left + right) / 2;
		MergeSort(a, left, mid);
		MergeSort(a, mid, right);
		Merge(a, left, mid, right);
	}
}

int main(){
	FIO
	
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; i++)cin >> a[i];
	MergeSort(a, 0, n);
	//int x[] = {1, 3, 5, 2, 4, 6};
	//Merge(x, 0, 3, 6);
	cout << a[0];
	for(int i = 1; i < n; i++)cout << ' ' << a[i];
	cout << '\n' << ans << '\n';
	return 0;
}

