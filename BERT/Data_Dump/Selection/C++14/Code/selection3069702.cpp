#include <iostream>
using namespace std;

using ll = long long;

#define for_(i,a,b) for(int i = (a);i < (b);i++)
#define rfor_(i,a,b) for(int i = (b)-1;i >= (a);i--)
#define rep(i,n) for_(i,0,(n))
#define rrep(i,n) rfor_(i,0,(n))

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int N;

int A[102];

int c;

int main(){
	cin.tie(0);
	
	cin>>N;
	rep(i, N)cin>>A[i];
	
	rep(i, N) {
		int minj = i;
		for_(j, i, N) {
			if(A[j] < A[minj])minj = j;
		}
		if(i != minj) {
			swap(A[i], A[minj]);
			c++;
		}
	}

	
	rep(i, N)cout<<(i>0?" ":"")<<A[i];
	cout<<endl<<c<<endl;
	
	return 0;
}

