#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define N 100

void print(int *a,int n){
	for(int i=0;i<n;i++){
		cout << a[i];
		if(i!=n-1){
			cout << " ";
		}
	}
}




int main () {
	int a[N],n;

	cin >> n;
	for(int i=0;i<n;i++){
		int k;
		cin >> k;
		a[i]=k;
	}
	print(a,n);
	

	for(int i=1;i<n;i++){
		cout << endl;
		int v = a[i];
		int j = i - 1;
		while(j>=0 && a[j]>v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1]=v;
		print(a,n);
	}
	cout << endl;
	return 0;
}
