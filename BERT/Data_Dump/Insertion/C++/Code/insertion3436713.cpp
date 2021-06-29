#include<iostream>
using namespace std;

void insertionSort(int a[], int n){
	for(int i = 1; i < n; i++){
		int tmp = a[i], j = i-1;
		while(j >= 0 && a[j] > tmp){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = tmp;
		cout << a[0];
		for(int j = 1; j < n; j++)
			cout << ' ' << a[j];
		cout << endl;
	}
}

int main(){
	int n, a[100];
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cout << a[0];
	for(int j = 1; j < n; j++)
		cout << ' ' << a[j];
	cout << endl;
	insertionSort(a, n);
	return 0;
}
