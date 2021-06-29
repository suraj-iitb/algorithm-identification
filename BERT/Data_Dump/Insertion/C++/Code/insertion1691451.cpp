#include <iostream>
using namespace std;

void print(int* a, int n){
	for(int i = 0; i < n-1; i++) cout << a[i] << " ";
	cout << a[n-1] << endl;
}

int main(){

	int n, v, j;
	int *a;

	cin >> n;
	a = new int[n];

	for(int i = 0; i < n; i++) cin >> a[i];

	print(a,n);

	for(int i = 1; i < n; i++){
		v = a[i];
		j = i-1;
		while(j >= 0 && a[j] > v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		print(a,n);
	}

	return 0;
}
