#include<iostream>

using namespace std;

int main(void){
	int A[100];
	int N,t,j;
	cin>>N;
	for(int i=0;i<N;i++) cin>>A[i];
	for(int k=0;k<N;k++){
		cout<<A[k];
		if(k!=N-1)cout<<" ";
		
	}
	cout<<endl;
	for(int i=1;i<N;i++){
		
		t=A[i];
		j=i-1;
		while(j>=0&&A[j]>t){
			A[j+1]=A[j];
			j--;
			A[j+1]=t;
		}
		for(int k=0;k<N;k++){
		cout<<A[k];
		if(k!=N-1)cout<<" ";
		
	}
		cout<<endl;
	}
	return 0;
}
