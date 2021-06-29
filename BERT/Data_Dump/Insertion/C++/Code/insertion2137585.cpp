#include <iostream>
using namespace std;

int n,a[100]={0};

void insertionsort(){
	int i,v=0,j=0;
	for(i=1;i<=n-1;i++){
		v=a[i];
		j=i-1;
		while(j>=0&&a[j]>v){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		for(j=0;j<n;j++){
			if(j!=n-1){
				cout<<a[j]<<" ";
			}
			else{
				cout<<a[j]<<endl;
			}
		}
		
	}
}

int main() {
	// your code goes here
	int i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	for(i=0;i<n;i++){
		if(i!=n-1){
			cout<<a[i]<<" ";
		}
		else{
			cout<<a[i]<<endl;
		}
	}
	insertionsort();
	return 0;
}
