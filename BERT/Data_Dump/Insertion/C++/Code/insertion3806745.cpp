#include <iostream>
using namespace std;
int n,a[1000];

void print(){
	int i=0;
	while(true){
		cout<<a[i];
		i++;
		if(i<n){
			cout<<" ";
		}else{
			break;
		}
	}
	cout<<endl;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int j=i-1,v=a[i];
		for(;j>=0 && a[j]>v;j--){
			a[j+1]=a[j];
		}
		a[j+1]=v;
		print();
	}
	return 0;
}
