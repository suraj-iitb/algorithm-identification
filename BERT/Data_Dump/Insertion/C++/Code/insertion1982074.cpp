// ahokusa.cpp
#include <iostream>
using namespace std;

void insertionSort(int a[],int n){
	int v;
	int j;
	for(int i=1;i<n;i++){
		v = a[i];
		j = i-1;
		while( j >= 0 && a[j] > v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		for(int i=0;i<n;i++){
			if(i>0){cout << " ";}
			cout << a[i];
		}
		cout << endl;
	}
}
int main(){
	int n;
	int a[100];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	for(int i=0;i<n;i++){
		if(i>0){cout << " ";}
		cout << a[i];
	}
	cout << endl;
	insertionSort(a,n);
	return 0;
}
