#include<iostream>

using namespace std;

int main(){
	int n;
	int a[108000];
	
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	
	for(int i = 0;i < n;i++){
		int j = i;
		while(j > 0 && a[j-1] > a[j]){
			int k = a[j];
			a[j] = a[j-1];
			a[j-1] = k;
			j--;
		}
		
		for(int j = 0;j < n;j++){
			if(j > 0)cout << " ";
			cout << a[j];
		}cout << endl;
	}	
}
