#include<iostream>
using namespace std;
int a[101];
int main() {
	int n,i,j,key;
	cin>>n;
	for(i=0; i<n; i++) {
		cin>>a[i];
	}

	for(int k=0; k<n; k++) {
		if(k==n-1)
			cout<<a[k];
		else
			cout<<a[k]<<" ";
	}
	cout<<'\n';

	for(i=1; i<n; i++) {
		key=a[i];
		j=i-1;
		while(j>=0&&a[j]>key) {
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;

		for(int k=0; k<n; k++) {
			if(k==n-1)
				cout<<a[k];
			else
				cout<<a[k]<<" ";
		}
		cout<<'\n';
	}


}
