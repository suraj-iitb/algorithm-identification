#include <iostream>
using namespace std;


int main(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
		}
	for(int i=1;i<=n;i++){
		for(int k=0;k<n;k++){
			cout << a[k];
			if(k<n-1){cout << " ";}
			else{cout << "\n";}
			}
		int key = a[i];
		for(int j=0;j<i;j++){
			if(a[j] > key) {
				int tmp = a[j];
				a[j] = key;
				a[i] = tmp;
				key = tmp;
				}
			}
		
		}
	}

