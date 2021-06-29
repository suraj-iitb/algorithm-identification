#include <bits/stdc++.h>
using namespace std;

int ary[100];
int n;

void output(){
	cout << ary[0];
	for(int i=1; i<n; i++){
		cout << " " << ary[i];
	}
	cout << "\n";
}

int main(){
	cin >> n;
	
	for(int i=0; i<n; i++) cin >> ary[i];
	
	for(int i=0; i<n; i++){
		int t = ary[i];
		int j;
		for(j=i-1; j>=0 && ary[j]>t; j--){
			ary[j+1] = ary[j];
		}
		ary[j+1] = t;
		output();
	}
	return 0;
}
