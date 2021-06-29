#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int BubbleSort(int A[],int N){
	int sw=0;
	bool flag=1;
	for(int i=0;flag;i++){
		flag=0;
		for(int j=N-1;i+1<=j;j--){
			if(A[j]<A[j-1]){
				swap(A[j],A[j-1]);
				sw++;
				flag=1;
			}
		}
	}
	return sw;
}

int main(){
	int A[100],N,sw;
	cin>>N;
	for(int t=0;t<N;t++)cin>>A[t];

	sw=BubbleSort(A,N);

	for(int t=0;t<N;t++){
		if(t) cout<<" ";
		cout<<A[t];
	}
	cout<<"\n";
	cout<<sw<<"\n";
	return 0;
}
