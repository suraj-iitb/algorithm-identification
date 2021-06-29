#include <iostream>
#include <algorithm>
using namespace std;

void trace(int a[],int n){
	for(int i=0;i<n-1;i++){
		cout << a[i] << " ";
	}
	cout << a[n-1] << endl;
}
void insertionSort(int a[],int n){
	int j, i, v;
	for(i=1;i<n;i++){
		v=a[i];
		j=i-1;
		while((j>=0)&&(a[j]>v)){
			a[j+1] = a[j];
			j--;
		}
		a[j+1]=v;
		trace(a,n);
	}
}



int main() {
	int n,j;
	int a[100];
	
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	
	trace(a,n);
	insertionSort(a,n);

	return 0;
}
