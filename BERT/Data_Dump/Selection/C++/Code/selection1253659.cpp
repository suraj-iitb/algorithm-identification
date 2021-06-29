#include <iostream>
#define MAX 100
using namespace std;

void trace(int a[],int n){
	for(int i = 0 ; i < n ; i++){
		if(i) cout << " ";
		cout << a[i];
	}
	cout << endl;
}

int selectionsort(int a[], int n){
	int sw = 0,min;
	bool flag;

	for(int i = 0 ; i < n - 1 ; i++){
		min = i;
		flag = 0;

		for(int j = i + 1 ; j < n ; j++){
			if(a[min] > a[j]){
				min = j;
				flag = 1;
			}
		}
		if(flag){
			sw++;
			swap(a[min],a[i]);
		}
	}

	return sw;
}

int main(){
	int n;
	int a[MAX];

	cin >> n;

	for(int i = 0 ; i < n ; i++){
		cin >> a[i];
	}

	int sw =selectionsort(a,n);
	trace(a,n);
	cout << sw << endl;

}
