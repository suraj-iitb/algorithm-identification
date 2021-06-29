#include <iostream>
using namespace std;
void bubbleSort(int& array){
	}
int main() {
	int n,count=0;
	cin >> n;
	int a[n]={};
	for(int i=0;i<n;i++){
		cin >> a[i];
		}
	for(int i=0;i<n;i++){
		for(int j=n-1;j>=i+1;j--){
			if(a[j] < a[j-1]){
				int tmp = a[j-1];
				a[j-1] = a[j];
				a[j] = tmp;
				count += 1;
				}
			}
		}
	for(int i=0;i<n;i++){
		cout << a[i];
		if(i==n-1)cout << "\n";
		else cout << " "; 
		}
	cout << count << "\n";
	}

