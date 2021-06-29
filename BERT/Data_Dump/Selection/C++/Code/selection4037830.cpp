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
	int ans = 0;
	
	rep(i,n){
		int minj = i;
		for(int j = i;j < n; ++j){
			if(arr[j] < arr[minj]){
				minj = j;
			}
		}
		if(minj != i) ans++;
		swap(arr[i], arr[minj]);
	}
	
	rep(i,n){
		if(i != n -1) cout << arr[i] << ' ';
		else cout << arr[i] << endl;
	}
	cout << ans << endl;
	return 0;
}
