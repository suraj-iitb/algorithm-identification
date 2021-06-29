#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int main(){
	int n;
	int a[101];
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	int cnt = 0;
	for(int i=0; i<n; i++){
		int mn= a [i];
		int mni = i;
		for(int j=i; j<n; j++){
			if(mn>a[j]){
				mn = a[j];
				mni = j;
			}
		}
		if(i!=mni){
			swap(a[i], a[mni]);
			cnt++;
		}
	}

	for(int i=0; i<n-1; i++){
		cout << a[i] << " ";
	}
	cout << a[n-1] << endl;
	cout << cnt << endl;
	return 0;
}
