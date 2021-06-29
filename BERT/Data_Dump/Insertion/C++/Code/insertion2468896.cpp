#include<iostream>
using namespace std;

int main(){
	int n,A[100];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	for(int i=0;i<n;i++){
		if(i>0) cout<<" ";
		cout<<A[i];
	}
	cout<<endl;
	for(int i=1;i<n;i++){
		int v=A[i];
		int j=i-1;
		while(j>=0&&A[j]>v){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=v;
		for(int k=0;k<n;k++){
			if(k>0) cout<<" ";
				cout<<A[k];
		}
		cout<<endl;
	}
		return 0;
}
