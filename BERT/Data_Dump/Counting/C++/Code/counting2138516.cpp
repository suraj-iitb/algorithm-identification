#include<iostream>
#include<vector>

using namespace std;

void countingsort(vector<int> &A,int k){

	vector<int> C(k+1,0);

	for (int j = 0; j < A.size(); j++){
		C[A[j]]++;
	}

	for (int i = 0; i < C.size(); i++){
		for (int j = 0; j < C[i]; j++){
			if ( i == C.size()-1 and j == C[i]-1){
				cout << i ;
			}else{
				cout << i << " ";
			}
		}
	}
	cout << endl;
}

int main(){

	int n; cin >> n;
	vector<int> A(n,0);
	int max = 0;
	for (int i = 0; i < n; i++){
		cin >> A[i];
		if (max < A[i]){
			max = A[i];
		}
	}
	countingsort(A,max);

return 0;
}
