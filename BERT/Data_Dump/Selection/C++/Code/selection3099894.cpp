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
		int mini = i;
		for (int j = i; j < n; ++j) {
			if( el[j] < el[mini]){
				mini = j;
			}
		}
		if(i!=mini){
			int c;
			c = el[i];
			el[i] = el[mini];
			el[mini] = c;
			cnt++;
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

