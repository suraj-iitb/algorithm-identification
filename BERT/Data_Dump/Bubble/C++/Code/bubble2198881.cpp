#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,i,j,cut=0,flag=1;
	int A[101];
	cin>>n;
	for(i=0;i<n;i++){
		cin>>A[i];
	}
	while(flag==1){
		flag=0;
		for(j=n-1;j>0;j--){
			if(A[j-1]>A[j]){
				swap(A[j-1],A[j]);
				cut++;
				flag=1;
			}
		}
	}
	for(i=0;i<n;i++){
		if(i!=0){
			cout<<" ";
		}
		cout<<A[i];
	}
	cout<<endl;
	cout<<cut<<endl;
	return 0;
}
