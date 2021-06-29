#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[100];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int v,j;
	for(int i=0;i<n;i++){
		v=a[i];
		j=i-1;
		while(j>=0&&a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		cout<<a[0];
		for(int k=1;k<n;k++){
			cout<<" "<<a[k];
		}
		cout<<endl;
	}
	return 0;
}

