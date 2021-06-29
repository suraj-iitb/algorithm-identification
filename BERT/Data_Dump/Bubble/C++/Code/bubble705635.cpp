#include <iostream>
#include <vector>
using namespace std;
typedef vector <int> IVEC;

int bubblesort(IVEC &A);

int main(void){
	IVEC A;
	int n, count;

	cin>>n;
	A.resize(n);
	
	for (int i=0; i<n; i++)
		cin>>A[i];

	count = bubblesort(A);

	for (int i=0; i<n; i++){
		if (i!=0) cout <<" ";
		cout<<A[i];
	}
	cout <<endl;
	cout << count << endl;
	return 0;
}

int bubblesort(IVEC &A){
	int lena = A.size(), count=0;
	for (int i=0; i<lena; i++){
		for (int j=lena-1; j>i; j--){
			if (A[j]<A[j-1]){
				int tmp = A[j];
				A[j] = A[j-1];
				A[j-1] = tmp;
				count++;
			}
		} 
	}
	return count;
}
