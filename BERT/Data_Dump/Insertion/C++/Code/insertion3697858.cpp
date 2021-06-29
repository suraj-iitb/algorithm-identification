#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int main(){
	int a[N];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int key,j;
	for(int i=0;i<n;i++){
		key = a[i];
		j = i-1;
		while(j>=0&&a[j]>key){
			a[j+1]=a[j];
			j--;
		}
		a[j+1] = key;
		for(int i=0;i<n;i++){
			if(i<n-1)
				cout<<a[i]<<" ";
			else
				cout<<a[i]<<endl;
		}
	}
	return 0;
} 
