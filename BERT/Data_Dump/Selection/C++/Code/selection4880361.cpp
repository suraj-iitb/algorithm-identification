#include <iostream>
using namespace std;

//~ SelectionSort

int main() {
	int n,count=0;
	cin >> n;
	int a[n]={};
	for(int i=0;i<n;i++){
		cin >> a[i];
		}
	for(int i=0;i<n;i++){
		int mini = i;
		for(int j=i;j<n;j++){
			if(a[j] < a[mini]){
				mini = j;
				}
			}
		if(mini != i){
			int tmp = a[mini];
			a[mini] = a[i];
			a[i] = tmp; 	
			count += 1;
			}
		}
	for(int i=0;i<n;i++){
		cout << a[i];
		if(i==n-1)cout << "\n";
		else cout << " "; 
		}
	cout << count << "\n";
	}

