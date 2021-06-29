#include <iostream>
#include <string>
#include <cmath>
#include<iomanip>
using namespace std;


int main() {
	bool judge = true;
	int n,temp,count = 0;
	cin>>n;
	int a[n+1];
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	a[0] = a[1];
	for(int i = 1;i <= n-1;i++){
		for(int j = n;j >= i + 1;j--){
			if(a[j] < a[j-1]){
				temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
				count = count + 1;
			}
		}
		judge = true;
		for(int i = 1;i <= n - 1;i++){
			if(a[i] > a[i+1]){
				judge = false;
			}
		}
		if(judge){
			break;
		}
	}
	for(int i = 1;i <= n;i++){
		if(i>1) cout<<" ";
		cout<<a[i];
	}
	cout<<endl;
	cout<<count<<endl;
}
