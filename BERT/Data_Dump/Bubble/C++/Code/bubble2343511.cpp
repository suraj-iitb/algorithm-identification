#include <iostream>
using namespace std;

int main() {	
	int a[105];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int count=0;
	int flag=1;
	while(flag){
		flag=0;
		for(int i=n-1;i>0;i--){
			if(a[i]<a[i-1]){
				int temp=a[i];
				a[i]=a[i-1];
				a[i-1]=temp;
				flag=1;
				count++;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		if(i>0) cout<<" ";
		cout<<a[i];
	}
	cout<<endl;
	cout<<count<<endl;
	
	return 0;
}
