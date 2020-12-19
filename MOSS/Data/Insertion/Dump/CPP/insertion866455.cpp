#include<cstdio>
#include<iostream>

using namespace std;

int main(void){

	int A[101];
	int i,n,tmp;

	cin>>n;
	for(int i=0;i<n;i++) cin>>A[i];

	for(int j=1;j<n;j++){
		for(int i=0;i<n;i++){
			cout<<A[i];
			if(i==n-1) cout<<endl;
			else cout<<" ";
		}
		tmp=A[j];
		i=j-1;
		while(i>=0&&A[i]>tmp){
			A[i+1]=A[i];
			i--;
		}
		A[i+1]=tmp;
	}

	for(int i=0;i<n;i++){
		cout<<A[i];
		if(i==n-1) cout<<endl;
		else cout<<" ";
	}

	return 0;
}
