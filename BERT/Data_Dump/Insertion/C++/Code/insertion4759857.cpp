#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int a[],int n){
	int j,v;
	for(int i=1;i<n;i++){
		v=a[i];
		j=i-1;
		while(j>=0&&a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		cout<<a[0];
		for(int k=1;k<n;k++)cout<<" "<<a[k];
		cout<<endl;
	}
} 


int main(){
	int n;
	cin>>n;
	int a[100];
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<a[0];
	for(int i=1;i<n;i++)cout<<" "<<a[i];
	cout<<endl;
	InsertionSort(a,n);
} 
