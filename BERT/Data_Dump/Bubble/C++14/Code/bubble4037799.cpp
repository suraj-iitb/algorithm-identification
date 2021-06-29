#include <iostream>
#include <vector>
#include <math.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	rep(i,n) cin >> arr[i];
	
	bool flag = true;
	int ans = 0;
	while(flag){
		flag = false;
		for(int i = n - 1; i >= 1; --i){
			if(arr[i] < arr[i - 1]){
				swap(arr[i],arr[i - 1]);
				flag = true;
				ans++;
			}
		}
	}
	
	rep(i,n){
		if(i != n - 1) cout << arr[i] << ' ';
		else cout << arr[i] << endl;
	}
	cout << ans << endl;
	return 0;
}
