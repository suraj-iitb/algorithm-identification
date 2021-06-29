#include <bits/stdc++.h> 
using namespace std; 

int main(){
	int n;
	cin >> n;
	int a[n];
	int c[100000];
	for(int i = 0; i < 100000; i++)
		c[i] = 0;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	
	for(int j = 1; j <= n; j++)
		c[a[j]]++;
	
	for(int k = 1; k < 100000; k++)
		c[k] = c[k] + c[k-1];
	
	int b[n];

	for(int i = n; i > 0; i--){
	    
		b[c[a[i]]] = a[i];
		
		c[a[i]]--;
	}
	
	
	
	for(int i = 1; i <= n; i++){
	    
		if(i > 1 ){
			cout << " ";
		}
		cout << b[i];
	}
	cout << endl;
	
	return 0;
}
