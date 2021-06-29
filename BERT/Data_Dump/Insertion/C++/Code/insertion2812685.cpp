#include <iostream>
using namespace std;


void outlist(int A[],int n){
	for(int i=0;i<n;i++){
		if (i>0){
			cout<<" ";
		}
    	cout<<A[i];
	}
  	cout<<endl;
}


int main(){
	int n;
	int A[1000];
	cin>>n;
	for(int i=0;i<n;i++){
			cin>>A[i];
	}
	outlist(A,n);
	for(int j=1;j<n;j++){
		int v=A[j];
		int k=j-1;
		while(k>=0&&A[k]>v){
			A[k+1]=A[k];
			k--;
		}
		A[k+1]=v;
		outlist(A,n);
	}
	return 0;
		
}
