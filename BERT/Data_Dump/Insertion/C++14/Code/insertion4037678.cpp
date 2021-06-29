#include <iostream>
#include <vector>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;

int main() {
	int n;cin >> n;
	vector<int> arr(n);
	rep(i,n) cin >> arr[i];
	
	rep(i,n){
		if(i != n - 1) cout << arr[i] << ' ';
		else cout << arr[i] << endl;;
	}
	
	for(int i = 1; i< n; ++i){
		int v = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > v){
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = v;
		rep(k,n){
			if(k != n - 1) cout << arr[k] << ' ';
			else cout << arr[k] << endl;
		}
	}
	return 0;
}
