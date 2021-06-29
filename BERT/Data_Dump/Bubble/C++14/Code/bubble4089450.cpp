#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> vc(n);
	for (int i=0;i<n;i++){
		cin >> vc.at(i);
	}
	bool flag = true;
	int ans = 0, tmp = 0;
	while (flag == true){
		flag = false;
		for (int j=n-1;j>0;j--){
			if (vc.at(j) < vc.at(j-1)){
				tmp = vc.at(j);
				vc.at(j) = vc.at(j-1);
				vc.at(j-1) = tmp;
				ans++;
				flag = true;
			}
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
