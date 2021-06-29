#include<iostream>
using namespace std;

int main(){
	int n;
	int m = 0;
	cin >> n;
	int a[n];
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	
	while(1){
		int flag = 0;
		for(int i = 0;i < n-1;i++){
			if(a[i] > a[i+1]){
				flag = 1;
				int k;
				k = a[i];
				a[i] = a[i+1];
				a[i+1] = k;
				m++;
			}
		}
		if(flag == 0){
			break;
		}
	}
	
	for(int i = 0;i < n-1;i++){
		cout << a[i] << " ";
	}
	cout << a[n-1] << endl;
	cout << m << endl;
}

