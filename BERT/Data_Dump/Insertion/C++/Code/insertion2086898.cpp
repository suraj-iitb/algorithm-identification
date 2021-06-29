#include<iostream>
using namespace std;
int main(){
	int n,temp,j;
	while(cin >> n){
		int k=0;
		int a[n];

		while(k!=n){
			cin >> a[k];
			k++;
		}

		for(int i=0;i<n;i++){
			temp = a[i];
			j = i-1;

			while(j>= 0 && a[j]>temp){
				a[j+1]=a[j];
				j--;
				a[j+1]=temp;
			}

			int l=0;

			while(l!=n-1){
				cout << a[l] << " ";
			l++;
			}
			cout << a[n-1]<< endl;

		}
	}
	return 0;
}
