#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<math.h>
using namespace std;

	bool sok(int* a,int n){
		for(int i=1;i<n;i++){
			if(a[i-1]>a[i])return false;
		}
		return true;
	}

int main(){
	int a[100],n;
	cin>>n;int cnt=0;
	
		for(int i=0;i<n;i++)cin>>a[i];
		int mini=0;
	for(int i=0;i<n;i++){
		mini=i;
		for(int j=i;j<n;j++){
			if(a[j]<a[mini]){
			mini=j;
			}
		}
		//if (sok(a,n))break;
		if(a[i]>a[mini]){
		swap(a[i],a[mini]);
		cnt++;
		}
	}
	
	for(int i=0;i<n-1;i++)cout<<a[i]<<" ";
	cout<<a[n-1]<<endl<<cnt<<endl;

	return 0;
}
