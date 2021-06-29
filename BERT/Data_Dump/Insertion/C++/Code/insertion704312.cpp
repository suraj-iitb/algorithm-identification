#include <iostream>
#include <vector>
using namespace std;

void Aout(vector <double> A, int n){
	for (int i=0; i<n; i++){
		if (i!=0) cout<<" ";
		cout<<A[i];
	}
	cout<<endl;
}

void insertionsort(vector <double> A, int n){
	double key;
	int i;
	for (int j=1; j<n; j++){
		key = A[j];
		i = j-1;
		while (i>=0){
			if (A[i] <= key) break;
			A[i+1] = A[i];
			i--;
		}
		A[i+1] = key;
		Aout(A, n);
	}
}

int main(void){
	int n;

	cin>>n;
	vector <double> A(n);

	for (int i=0; i<n; i++)
		cin>>A[i];
	Aout(A, n);
	insertionsort(A, n);

	return 0;
}
