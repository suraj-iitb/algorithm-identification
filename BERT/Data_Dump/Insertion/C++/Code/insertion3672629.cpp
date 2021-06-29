#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n){
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			int k=i;
			for(int j=i-1;j>=0;j--){
				if(a[k]<a[j]){
					int temp=a[k];
					a[k]=a[j];
					a[j]=temp;
				}
				k--;
			}
			cout<<a[0];
			for(int l=1;l<n;l++){
				cout<<" "<<a[l];
			}
			cout<<endl;
		} 
	}
	return 0;
} 
