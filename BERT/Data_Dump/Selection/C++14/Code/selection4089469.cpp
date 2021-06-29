#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> vc(n);
	for (int i=0;i<n;i++){
		cin >> vc.at(i);
	}
	
	int min, tmp, ans=0;
	for (int i=0;i<n;i++){
		min = i;
		for (int j=i;j<n;j++){
			if (vc.at(j) < vc.at(min)){
				min = j;
			}
        }
        if (min != i){
		tmp = vc.at(i);
		vc.at(i) = vc.at(min);
		vc.at(min) = tmp;
		ans++; 
        }

	}
	
	for (int i=0;i<n;i++){
		if (i!=n-1){
			cout << vc.at(i) << " ";
		}
		else{
			cout << vc.at(i) << endl;
		}
	}
	cout << ans << endl;
}
