#include <bits/stdc++.h>
using namespace std;
#define ref goto refrain

void sort(int*a,int n){
	int count=0;
	for(int i=0;i<n;i++){
		int minj=i;
		for(int j=i;j<n;j++){
			if(a[j]<a[minj]) minj=j;
		}
		if(i!=minj){
			int tem=a[i];
			a[i]=a[minj];
			a[minj]=tem;
			count++;
		}
	}
	cout<<a[0];
	for(int i=1;i<n;i++){
		cout<<" "<<a[i];
	}
	cout<<endl;
	cout<<count<<endl;
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,n);
	return 0;
}
