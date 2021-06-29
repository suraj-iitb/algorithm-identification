#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

void printarray(int a[], int n){
	for (int i=0; i<n; i++){
		if (i==n-1){
			cout << a[i] << endl;
		}
		else{
			cout << a[i] << ' ';
		}
	}

}

void insertionsort(int a[], int n){
	for (int i=0; i<n; i++){
		int v = a[i];
		int j = i-1;
		while (j >= 0 && a[j] > v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		printarray(a,n);
	}
}


int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	insertionsort(a,n);

	return 0;
}
