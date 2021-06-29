#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[100];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(i!=n-1)
		    cout<<a[i]<<" ";
		else
		    cout<<a[i]<<endl;
	}
	for(int i=1;i<n;i++){
		int k=a[i];
		int j=i-1;
		while(j>=0 and a[j]>k){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=k;
		for(int i=0;i<n;i++){
		    if(i!=n-1)
			    cout<<a[i]<<" ";
			else
			    cout<<a[i]<<endl;
		}
	}
	return 0;
}
