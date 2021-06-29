#include <iostream>
using namespace std;

int main(){
	int a[100],n;
	cin >> n;
	for(int i = 0;i < n;++i){
		cin >> a[i];
	}
	for(int j = 0;j < n;++j){
		if(j) cout << " ";
		cout << a[j];
	}
	cout << endl;
	for(int i = 1;i < n;++i){
		int j = i - 1,tmp = a[i];
		while(j >= 0 && a[j] > tmp){
			a[j + 1] = a[j];
			--j;
		}
		a[j + 1] = tmp;
		for(j = 0;j < n;++j){
			if(j) cout << " ";
			cout << a[j];
		}
		cout << endl;
	}
	return 0;
}
