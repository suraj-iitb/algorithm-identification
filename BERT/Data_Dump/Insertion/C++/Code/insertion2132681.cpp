#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int a[100],n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	
	for(int i=0;i<n;i++){
		int v=a[i];
		int j=i-1;
		while(j>=0&&a[j]>v){
			swap(a[j+1],a[j]);
			j--;
		}
		for(int k=0;k<n;k++){
			cout<<a[k];
			if(k==n-1)cout<<endl;
			else cout<<" ";
		}
	}
	return 0;
}
