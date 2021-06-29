#include<bits/stdc++.h>
using namespace std;

void trace(int A[], int N){
	for(int i = 0; i < N; i++){
		cout<<A[i];
		if(i < N - 1) cout<<" ";
	}
	cout<<endl;
}

int Bubble_Sort(int A[], int N) {
	int count = 0;
	int flag = 1;

	while(flag){
		flag = 0;
		for(int j = N - 1; 1 <= j; j--){
			if(A[j] < A[j - 1]){
				swap(A[j], A[j - 1]);
				count++;
				flag = 1;
			}
		}
	}

	trace(A, N);

	return count;
}

int main(){	
	int N, A[100];

	cin>>N;

	for(int i = 0; i < N; i++) cin>>A[i];
	
	cout<<Bubble_Sort(A, N)<<endl;
	
	return 0;
}
