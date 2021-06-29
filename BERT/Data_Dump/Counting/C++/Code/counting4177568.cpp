#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	int c[10000] = {0};
	for(int i=0;i<n;++i){
		cin >> a[i];
	}
	for(int i=0;i<n;++i){
		c[a[i]]++;
	}
	for(int i=1;i<10000;++i){
		c[i] = c[i] + c[i-1];
	}
	for(int j=n-1;j>=0;--j){
		b[c[a[j]]-1] = a[j];
		c[a[j]]--;
	}
	for(int i=0;i<n;++i){
		cout << b[i];
		if(i!=n-1)cout << " ";
		else cout << "\n";
	}
}
