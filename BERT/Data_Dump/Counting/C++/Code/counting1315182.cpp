#include<iostream>
#include<vector>
#define VMAX 10001
using namespace std;

void CountingSort(std::vector<int>& a, std::vector<int>& b, int n){
	std::vector<int> c(VMAX,0);
	for(int i=1;i<=n;i++){
		c[a[i]]++;
	}
	for(int i=1;i<=VMAX;i++){
		c[i] = c[i] + c[i-1];
	}
	for(int i=n;i>0;i--){
		b[c[a[i]]] = a[i];
		c[a[i]]--;
	}
}

int main(){

	int n,in;
	std::vector<int> v(2000010);
	std::vector<int> b(2000010);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	CountingSort(v,b,n);

	for(int i=1;i<=n;i++){
		if(i>1) cout << " ";
		cout << b[i];
	}
	cout << endl;
	return 0;
}
