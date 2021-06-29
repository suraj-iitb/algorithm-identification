#include <iostream>
using namespace std;

int main(){
	int v,n, i, j;
	int A[100];

	cin>>n;
	for(int i=0; i<n; i++) cin>>A[i];
	for(int ii=0; ii<n; ii++){
			if(ii>0) cout<<" ";
			cout<<A[ii];
		}
	cout<<"\n";
	for(i=1; i<n; i++){
		
		v = A[i];
		j = i-1;
		while(j>=0 && A[j]>v){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = v;
		for(int ii=0; ii<n; ii++){
			if(ii>0) cout<<" ";
			cout<<A[ii];
		}
		cout<<"\n";
	}
	
	
	return 0;
}
