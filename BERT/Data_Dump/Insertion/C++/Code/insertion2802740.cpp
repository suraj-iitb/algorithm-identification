#include<iostream>
using namespace std;

void insertionSort(int a[],int n){
	int i,k;
	for(i=1; i<=n-1; i++){
		int v=a[i];
		int j=i-1;
		while(j>=0 && a[j]>v){
			a[j+1]=a[j];
			j--;
			a[j+1]=v;
		}
		for(k=0; k<n; k++){
			cout<<a[k];
			if(k!=n-1) cout<<" ";
		}
		cout<<"\n";
	}
}

int main(){
	int n,i;
	cin>>n;
	int a[n];
	for(i=0; i<n; i++){
		cin>>a[i];
	}
	for(i=0; i<n; i++){
		cout<<a[i];
		if(i!=n-1) cout<<" ";
	}
	cout<<"\n";
	insertionSort(a,n);
	return 0;
}
