#include<stdio.h>
#include<queue>
#include<vector>
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int main(){
	int j,n,v,a[105];
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(j=0;j<n-1;j++)
		cout<<a[j]<<" ";
	cout<<a[n-1]<<endl;
	for(int i=1;i<n;i++){
		v=a[i];
		j=i-1;
		while(j>=0&&a[j]>v){
			a[j+1]=a[j];
			j--;	
		}
		a[j+1]=v;
		for(j=0;j<n-1;j++)
			cout<<a[j]<<" ";
		cout<<a[n-1]<<endl;
	}
	return 0;
}

