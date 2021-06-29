#include <iostream>
#include <stdlib.h>
#define VMAX 10001
#define NMAX 2000001
using namespace std; 
int n, k=VMAX;
int A[NMAX], B[NMAX], C[VMAX];


int main() {
	
	cin >> n;
	
	int i;
	
	for(i=1; i < n+1; i++)
	{
		cin >> A[i]; 
	}
	
	for(i=0; i < k+1;i++)
	{
		C[i] = 0;
	}
	
	for(i=1; i<n+1;i++)
	{
		C[A[i]]++;
	}
	
	for(i=0; i < k+1; i++)
	{
		C[i] = C[i] + C[i-1];
	}

	for(i=n; i>0; i--)
	{
		B[C[A[i]]] = A[i];
		C[A[i]]--;
	}
	
	for(i=1; i<n+1; i++)
	{
		if(i-1) cout << " ";
		cout << B[i];
	}
	cout << endl;
//	system("pause");	
	return 0;
}
