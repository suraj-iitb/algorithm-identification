#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,t=0;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
				t++;
			}
		}
	}
	for(int k=0;k<n;k++){
		cout << a[k];
		if(k!=n-1) cout << ' ';
	}
	cout << '\n' << t << '\n';
	return 0;
} 
