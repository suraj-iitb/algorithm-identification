#include <iostream>
using namespace std;

int n;
int a[100];

void put_array(int* arr, int size){
	for(int i=0; i<size; i++){
		cout << arr[i];
		if(i == size-1) cout << endl;
		else cout << " ";
	}
}

int main(void){
	int n;
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];
	
	put_array(a, n);
	for(int i=1; i<n; i++){
		int v = a[i];
		int j = i-1;
		while(j>=0 && a[j]>v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		put_array(a, n);
	}
	
	return 0;
}
