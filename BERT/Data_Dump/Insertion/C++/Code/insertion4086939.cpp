 #include <bits/stdc++.h>
 using namespace std;
 void insertionSort(int*, int);
 
 int main(void){
 	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	insertionSort(a, n);
	return 0;
 }
 
 void insertionSort(int* a, int n){
 	for(int i=0; i<n; i++){
		int v = a[i];
		int j = i - 1;
		while(j>=0 && a[j] > v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		//puts
		cout << a[0];
		for(int i=1; i<n; i++){
			cout << " " << a[i];
		}
		cout << endl;
	}
	return;
 }
