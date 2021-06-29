#include <iostream>
using namespace std;

using ll = long long;

#define for_(i,a,b) for(int i = (a);i < (b);i++)
#define rfor_(i,a,b) for(int i = (b)-1;i >= (a);i--)
#define rep(i,n) for_(i,0,(n))
#define rrep(i,n) rfor_(i,0,(n))

int N;

int A[102];

int c;

int main(){
	cin.tie(0);
	
	cin>>N;
	rep(i, N)cin>>A[i];
	
	bool f = true;
	while(f) {
		f = false;
		rfor_(i, 1, N) {
			if(A[i] < A[i-1]) {
				int s = A[i];
				A[i] = A[i-1];
				A[i-1] = s;
				c++;
				f = true;
			}
		}
	}
	
	rep(i, N)cout<<(i>0?" ":"")<<A[i];
	cout<<endl<<c<<endl;
	
	return 0;
}

