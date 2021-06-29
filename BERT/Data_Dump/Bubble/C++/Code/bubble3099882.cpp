#include <stdio.h>
#include <iostream>
using namespace std;


#define abs(N) ((N>0)?N:-1*N)
#define lt(A,B) ((A>B)?B:A)
#define gt(A,B) ((A<B)?B:A)
#define print(S) (cout << S)
#define println(S) (cout << S << endl)

int main(){
	int n;
	cin >> n;

	int el[n];
	for (int i = 0; i < n; ++i) {
		cin >> el[i];
	}
	int cnt=0;
	for (int i = 0; i < n; ++i) {
		for (int j = n-1; j >= i+1; --j) {
			if( el[j] < el[j-1]){
				int c;
				c = el[j];
				el[j] = el[j-1];
				el[j-1] = c;
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if(i > 0) cout << " ";
		cout << el[i];
	}
	cout << endl;
	println(cnt);


	return 0;
}

