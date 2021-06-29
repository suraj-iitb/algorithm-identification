#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> vc(n);
	for (int i=0;i<n;i++){
		cin >> vc.at(i);
	}
	for (int i=0;i<n;i++){
		int v, j;
		v = vc.at(i);
		j = i - 1;
		while (j>=0 && vc.at(j)>v){
			vc.at(j+1) = vc.at(j);
			j--;
		}
		vc.at(j+1) = v;
		for (int i=0;i<n;i++){
			if (i<n-1){
			cout << vc.at(i) << " "; 
			}
			else{
				cout << vc.at(i) << endl;
			}
		}
	}

}
