#include <bits/stdc++.h>
using namespace std;

int main(void){
	int n;
	int a[200];
	int swap = 0;

	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	for(int i=0; i<n; i++){
		for(int j=n-1; j>i; j--){
			if(a[j] < a[j-1]){
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				swap++;
			}
		}
	}

	for(int i=0; i<n; i++){
		if(i!=n-1) printf("%d ", a[i]);
		else printf("%d\n", a[i]);
	}
	printf("%d\n", swap);

	return 0;
}
