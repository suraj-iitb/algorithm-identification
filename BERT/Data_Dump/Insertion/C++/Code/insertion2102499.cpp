#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int n,a[101];
	cin >>n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n-1;i++)
		cout << a[i] << ' ';
	cout<< a[n-1] << endl;
	for(int k = 1;k <n;k++){
		int v,j;
		v = a[k];
		j = k-1;
		while(j >= 0 && a[j] > v){
			a[j+1] = a[j];
			j--;
			a[j+1] = v;
		}
		for(int i=0;i<n-1;i++)
			cout << a[i] << ' ';
		cout<< a[n-1] << endl;
	}

	return 0;
}
