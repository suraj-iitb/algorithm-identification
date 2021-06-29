#include <iostream>
using namespace std;

int main() {
	int i,j;
	int N;
	cin>>N;
	
	int A[N];
	int key;
	for(i=0;i<N;i++){
		cin>>A[i];
	}
	
	for(i=0;i<N;i++){
		key=A[i];
		j=i-1;
		while(j>=0&&A[j]>key){
			A[j+1]=A[j];
			j--;
		}
		A[j+1]=key;
		for(int n=0;n<N;n++){
			cout<<A[n];
			if(n!=N-1)cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
