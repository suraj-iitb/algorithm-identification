#include<iostream>
#include<vector>

using namespace std;

struct card{
	int num;
	char mark;
	int order;
};

int partition(vector<int> &A,vector<char> &B,vector<int> &C,int p,int r){ 
		int x = A[r];
		int i = p - 1;

		for (int j = p; j < r; j++){
				if (A[j] <= x){ 
						i++;
						int itmp = A[i];
						A[i] = A[j];
						A[j] = itmp;
						char ctmp = B[i];
						B[i] = B[j];
						B[j] = ctmp;
						int iitmp = C[i];
						C[i] = C[j];
						C[j] = iitmp;
				}   
		}   

		int itmp = A[i+1];
		A[i+1] = A[r];
		A[r] = itmp;
		char ctmp = B[i+1];
		B[i+1] = B[r];
		B[r] = ctmp;
		int iitmp = C[i+1];
		C[i+1] = C[r];
		C[r] = iitmp;

		return i+1;
}

void quicksort(vector<int> &A,vector<char> &B,vector<int> &C,int p,int r){
	if (p < r){
		int q = partition(A,B,C,p,r);
		quicksort(A,B,C,p,q-1);
		quicksort(A,B,C,q+1,r);
	}
}

bool check(vector<int> &A,vector<int> &C,int n){
	for (int i = 1; i < n; i++){
		if (A[i-1] == A[i] and C[i-1] > C[i]) return false;
	}
	return true;
}

int main(){
		int n; cin >> n;
		vector<int> A(n);
		vector<char> B(n);
		vector<int> C(n);

		for (int i = 0; i < n; i++){
			cin >> 	B[i] >> A[i];
			C[i] = i;
		}

		quicksort(A,B,C,0,n-1);
		if(check(A,C,n)){
			cout << "Stable" << endl;
		}else{
			cout << "Not stable" << endl;
		}

		for (int i = 0; i < n; i++){
				cout << B[i] << " " << A[i] << endl;
		}
		return 0;
}
