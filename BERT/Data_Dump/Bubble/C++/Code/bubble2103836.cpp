#include<iostream>

using namespace std;

int main(){
	
	
	int n;
	cin>>n;
	int a[n];
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	
	int count = 0;
	bool flag = true;
	while(flag){
		flag = false;
		for(int i=n-1;i>0;i--){
			if(a[i-1] > a[i]){
				int temp = a[i];
				a[i] = a[i-1];
				a[i-1] = temp;
				count++;
				flag = true;
			}
		}
	}
	
	
	cout << a[0];
	for(int i=1;i<n;i++){
		cout<<' '<<a[i];
	}
	cout<<endl;
	cout<<count<<endl;
	
	return 0;

}
