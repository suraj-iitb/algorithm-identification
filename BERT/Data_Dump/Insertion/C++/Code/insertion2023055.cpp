#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n;
	int a[1000];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		sort(a,a+i+1);
		for(int i=0;i<n;i++){
			if(i) cout<<" ";
			cout<<a[i];
		}
		cout<<"\n";
	}
	return 0;
}
