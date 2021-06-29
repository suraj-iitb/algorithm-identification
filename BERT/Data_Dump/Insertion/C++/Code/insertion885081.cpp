#include <bits/stdc++.h>
using namespace std;

void Trace(int* a, int n){
	for(int i=0; i<n; i++){
		if(i!=n-1) printf("%d ", a[i]);
		else printf("%d\n", a[i]);
	}
}

int main(void){
	int n;
	int a[200];
	cin >> n;

	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	Trace(a, n);

	for(int i=1; i<n; i++){
		int key = a[i];
		int j=i-1;
		for(; j>=0 && a[j] > key; j--){
			a[j+1] = a[j];
		}
		a[j+1] = key;

		Trace(a, n);
	}


	return 0;
}
