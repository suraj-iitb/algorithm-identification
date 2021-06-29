#include <bits/stdc++.h>
using namespace std;



int main(){
	int n,v;
	cin>>n;

	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];

	cout<<a[0];
	for(int i=1;i<n;i++)cout<< " " << a[i];
	cout<<endl;

	for(int i=1;i<n;i++){
		v=a[i];
		
		for(int j=i-1;j>=0 && a[j]>v;j--){
			a[j+1]=a[j];
			a[j]=v;
		}


		cout<<a[0];
		for(int i=1;i<n;i++)cout<< " " << a[i];
		cout<<endl;
	}

	

	return 0;
}


