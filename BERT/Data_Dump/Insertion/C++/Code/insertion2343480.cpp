#include <iostream>
using namespace std;

int main() {
	int a[105];
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	cout<<a[0];
	for(int i=1;i<n;i++){
		cout<<" "<<a[i];
	}
	cout<<endl;
	
	for(int i=1;i<n;i++){
		int temp=a[i];
		int j=i-1;
		while (j>=0 && a[j]>temp){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
		
		cout<<a[0];
		for(int i=1;i<n;i++){
			cout<<" "<<a[i];
		}
		cout<<endl;
		
	}
	
	return 0;
}
