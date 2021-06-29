#include <iostream>
#include <algorithm>
#include <cstring>
#define rep(i,o,u) for(i = o;i <= u; i++)
using namespace std;

int a[101];
int main(){
	int n;
	int i,j;
	cin >> n;
	rep(i,1,n) cin >> a[i];
	rep(i,1,n) {
		sort(a+1,a+1+i);
		rep(j,1,n-1) cout << a[j] << " ";
		cout << a[j] << endl;
	}
	return 0;
}
