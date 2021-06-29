#include<iostream>
#include<algorithm>
using namespace std;
int a[2000005],n;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		cout<<a[i];
		if(i!=n-1) cout<<" ";
		else cout<<endl;
	}
	return 0;
} 
