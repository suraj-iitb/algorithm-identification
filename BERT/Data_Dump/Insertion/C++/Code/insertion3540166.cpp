#include <iostream>

//insertionsort

using namespace std;


void printA(int x[], int n){
	for(int i=0;i<n;i++){
		cout << x[i];
		if(i==n-1)cout<<"\n";
		else cout << " ";
	}
}

int main(){
	int n,v,j;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	
	printA(a,n);
	
	for(int i=1;i<n;i++){
		v = a[i];
		j = i-1;
		while(j>=0 && a[j] > v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;
		printA(a,n);
	}
	return 0;
}
