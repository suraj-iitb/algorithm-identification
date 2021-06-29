#include <iostream>
#include <string>
#include <cmath>
#include<iomanip>
using namespace std;


int main() {
	bool judge = true;
	int n,temp,min,count = 0;
	cin>>n;
	int a[n+1];
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	a[0] = a[1];
	for(int i = 1;i <= n-1;i++){
		min = i;
		for(int j = i+1;j <= n;j++){
			if(a[j] < a[min]){
				min = j;
			}
		}
		if(min != i){
			temp = a[i];
			a[i] = a[min];
			a[min] = temp;
			count = count + 1;
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
