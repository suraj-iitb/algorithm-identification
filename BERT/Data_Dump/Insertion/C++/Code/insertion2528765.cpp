#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m[1000],g = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> m[i];
	}
	for(int o = 0; o < n; o++){
		sort(m,m+o+1);
		for(int j = 0; j < n;j++){

			if(j)cout << " ";
			cout << m[j];
		}
	cout << endl;
	}
	return 0;
}
