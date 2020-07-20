#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i<n;i++){
		cin>>a[i];
	}
	int flag = 1;
	int kaisu = 0;
	while(flag){
		flag = 0;
		for(int i = n-1;i>0;i--){	
			if(a[i] <a[i-1]){
				int o;
				o = a[i];
				a[i] = a[i-1];
				a[i-1] = o;
				flag = 1;
				kaisu ++;
			}
		}
	}
	for(int i = 0;i<n-1;i++){
		cout<<a[i]<<" ";
	}
	cout<<a[n-1]<<endl;
	cout<<kaisu<<endl;
	return 0;
}
