#include <iostream>
#include <string>
#include <cmath>
#include<iomanip>
using namespace std;


int main() {
	bool judge = true;
	int n,temp,count = 0,point,min;
	cin>>n;
	int a[n+1];
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	min = a[1];
	for(int i = 1;i <= n;i++){
		if(a[i]<min){
			min = a[i];
		}
	}
	a[0] = min;
	for(int j = 1;j <= n;j++){
		if(j>1) cout<<" ";
		cout<<a[j];
	}
		cout<<endl;
	for(int i = 2;i <= n;i++){
		point = i;
		for(int j = 0;j <= i - 1;j++){
			if(a[j]<=a[i] && a[j+1]>a[i]){
				point = j+1;
				break; 
			}
		}
		if(point != i){
			temp = a[i];
			for(int j = i-1;j >= point;j--){
				a[j+1] = a[j];
			}
			a[point] = temp;
		}
		for(int j = 1;j <= n;j++){
			if(j>1) cout<<" ";
			cout<<a[j];
		}
		cout<<endl;
	}
}
