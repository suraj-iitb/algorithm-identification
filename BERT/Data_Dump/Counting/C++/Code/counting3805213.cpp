#include <iostream>

using namespace std;

#define MAX 2000000
#define AMAX 10000

int main(){

	int n;
	int A[MAX],cnt[AMAX+1];

	int *B;
	cin >> n;

	B=new int[n];

	for(int i=0;i<n;i++) cin >>A[i];

	for(int i=0;i<=AMAX;i++) cnt[i]=0;

	for(int k=0;k<n;k++) cnt[A[k]]++;

	for(int j=1;j<AMAX;j++) cnt[j]=cnt[j]+cnt[j-1];


	for(int k=n-1;k>=0;k--){
		B[cnt[A[k]]-1]=A[k];
		cnt[A[k]]--;
	}
	for(int i=0;i<n;i++){ 
		if(i) cout<<" ";
		cout << B[i];
	}
	cout<<endl;

	delete[] B;
	return 0;
}

