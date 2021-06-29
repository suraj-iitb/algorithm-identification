#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	int n;
	int a[100];
	cin >> n;
	for(int i=0; i<n; i++) cin >> a[i];

	for(int i=0; i<n; i++){
		int j;
		int tmp = a[i];
		for(j=0; j<i; j++){
			if(a[i]<a[j]){
				break;
			}
		}
		for(int k=i-1; k>=j; k--){
			a[k+1] = a[k];
		}
		a[j] = tmp;

		for(int k=0; k<n-1; k++){
			cout << a[k] << " ";
		}
		cout << a[n-1] << endl;
	}
	return 0;
}
