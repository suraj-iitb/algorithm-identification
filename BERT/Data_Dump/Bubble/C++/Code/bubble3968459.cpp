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
	int n,A[MAX],k=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>A[i];
	int flag=1,i=0;
	while(flag){
		flag=0;
		for(int j=0;j<n-1-i;j++){
			if(A[j]>A[j+1]){
				flag=1;
				k++;
				int temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
		i++;
	}
	print(A,n);
	cout<<k<<endl;
	return 0;
}
