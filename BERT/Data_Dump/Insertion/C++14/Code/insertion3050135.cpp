#include <iostream>
using namespace std;

using ll = long long;

#define for_(i,a,b) for(int i = (a);i < (b);i++)
#define rfor_(i,a,b) for(int i = (b)-1;i >= (a);i--)
#define rep(i,n) for_(i,0,(n))
#define rrep(i,n) rfor_(i,0,(n))

int N;
int A[1001];

int main(){
	cin.tie(0);
	
	cin>>N;
	rep(i, N)cin>>A[i];
	
	for_(i, 0, N) {
	    rfor_(j, 0, i) {
	        if(A[j] < A[j+1])break;
	        int v = A[j+1];
	        A[j+1] = A[j];
	        A[j] = v;
	    }
	    rep(j, N) {
	        cout<<A[j];
	        if(j<N-1)cout<<' ';
	    }
	    cout<<endl;
	}

	return 0;
}


