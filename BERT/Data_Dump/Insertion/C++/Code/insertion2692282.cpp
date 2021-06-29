#include <iostream>
using namespace std;

void printArr(int* a, int len){
	for(int i=0; i<len; ++i){
		if(i != 0) cout << " ";
		cout << *(a + i);
	}
	cout << "\n";
}

int main(){
	
	int n;
	cin >> n;
	
	int a[n];
	for(int i=0; i<n; ++i) cin >> a[i];
	
	printArr(a, n);	
	for(int i=1; i<n; ++i){
		int t = a[i];
		if(a[i-1] > t){
			int j=i;
			do{
				a[j] = a[j-1];
				j--;
			} while(j > 0 && a[j-1] > t);
			a[j] = t;
		}	
		printArr(a, n);
	}
	
	return 0;
}

