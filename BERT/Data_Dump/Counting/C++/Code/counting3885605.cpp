#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAX 2000000
#define VMAX 10000



int main(){
	unsigned short *A, *B;
	int C[VMAX+1];
	int n;
	cin>>n;
	A = (unsigned short *)malloc(sizeof(unsigned short)*n+1);
	B = (unsigned short *) malloc(sizeof(unsigned short)*n+1);

	for(int i=0; i<=VMAX; i++) C[i] = 0;

	for(int i=0; i<n; i++){
		cin>>A[i];
		C[A[i]]++;
	}
	for(int i=1; i<=VMAX; i++) C[i] = C[i]+C[i-1]; //这里必须有等号

	for(int i=0; i<n; i++){
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}

	for(int i=1; i<=n; i++){
		if(i!=1) cout<<" ";
		cout<<B[i];
	}
	cout<<endl;

	return 0;
}
