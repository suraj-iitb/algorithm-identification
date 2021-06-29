#include <iostream>
using namespace std;
#define MAX 100
void print(int A[],int n){
		for(int i=0;i<n;i++){
			if(i>0)
				cout<<" ";
			cout<<A[i];	
		}
		cout<<endl;	
}
int main(){
	int n,A[MAX],v,j;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];
	print(A,n);	
	for(int i=1;i<n;i++){
		v=A[i];
		j=i-1;
		while(j>-1 && A[j]>v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		print(A,n);	
	}
	
	return 0;
}
