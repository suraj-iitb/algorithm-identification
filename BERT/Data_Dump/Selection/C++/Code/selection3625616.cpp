#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<int> A(N);
	int roop;
	int swaped=0;
	for(roop=0;roop<N;roop++){
		cin >> A[roop];
	}
	int roop2,minrp2;
	for(roop=0;roop<N;roop++){
		minrp2=roop;
		for(roop2=roop;roop2<N;roop2++){
			if(A[roop2]<A[minrp2])
				minrp2=roop2;
		}
		if(minrp2-roop){
			swap(A[roop],A[minrp2]);
			swaped++;
		}
	}
	for(roop=0;roop<N;roop++){
		cout << A[roop];
		if(roop<N-1){
			cout << " ";
		}else{
			cout << endl;
		}
	}
	cout << swaped << endl;
	return 0;
}
