#include <iostream>
#include <algorithm>

using namespace std;

static const int N = 1000;
#define rep(i,a) for(int i = 0 ; i < a ; i ++)
#define loop(i,a,b) for(int i = a ; i < b ; i ++)
int main(void){
	int n,a[N];
	cin>>n;
	rep(i,n)cin>>a[i];

	rep(i,n){
		int v = a[i];
		for(int j = i-1 ; j >= 0  && a[j] > v; j --){
			swap(a[j],a[j+1]);
		}
		rep(j,n)cout<<a[j]<<(j==n-1?'\n':' ');
	}

}
