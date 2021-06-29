#include <bits/stdc++.h>
using namespace std;

int main(){
	long N;
	cin >> N;
	vector<long> A(N);
	for(long i=0; i<N; i++) cin >> A.at(i);

	long buf;
	long count = 0;
	bool flg = true;
	while(flg){
		flg = false;
		for(long j=N-1; j>0; j--){
			if(A.at(j) < A.at(j-1)){
				buf = A.at(j);
				A.at(j) = A.at(j-1);
				A.at(j-1) = buf;
				flg = true;
				count++;
			}
		}
	}

	for(long i=0; i<N; i++){
		cout << A.at(i);
		if(i<N-1) cout << " ";
	}
	cout << endl;
	cout << count << endl;
}

