#include <iostream>
using namespace std;

int main(){
	int n, v, a[1000], i, j, k;
	cin >> n;
	for(i = 0; i < n; i++){
		cin >> a[i];
	}
	for(k = 0; k < n-1; k++){
			cout << a[k] << ' ';
	}
	cout << a[n-1] << endl;
	
	for(i = 1; i < n; i++){
		v = a[i];
		j = i-1;
		while(j >= 0 and a[j] > v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		
		for(k = 0; k < n-1; k++){
			cout << a[k] << ' ';
		}
		cout << a[n-1] << endl;
	}
	
	return 0;
}
