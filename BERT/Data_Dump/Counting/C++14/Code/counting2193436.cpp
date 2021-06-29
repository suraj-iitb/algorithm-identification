#include<iostream>
#include<cstdlib>

using namespace std;

void CountingSort(int A[],int B[],int k,int n);

int main(){
	int n,*A,*B;
	cin>>n;
	A = new int[n]; B = new int[n];
	A = A-1; B = B-1;

	int k=0;
	for(int i=1;i<=n;i++){
		cin>>A[i];
		k = (k<A[i])? A[i]:k;
	}

	CountingSort(A,B,k,n);

	for(int i=1;i<=n;i++){
		if(i-1) cout<<" ";
		cout<<B[i];
	}
	cout<<endl;

	delete [] (A+1),delete [] (B+1);

}

void CountingSort(int A[],int B[],int k,int n){
	int *C; C = new int[k+1];
	for(int i=0;i<=k;i++) C[i] = 0;

	for(int j=1;j<=n;j++) C[A[j]]++;

	for(int i=1;i<=k;i++) C[i] = C[i]+C[i-1];

	for(int j=n;j>=1;j--){
		B[C[A[j]]] = A[j];
		C[A[j]]--;
	}
	
	delete [] C;
}
