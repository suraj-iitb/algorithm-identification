#include<iostream>
using namespace std;

int out(int *A,int N){
	int i;
	for (i=0;i<=N-2;i++){
		cout << A[i] <<" ";
	}
	cout << A[N-1] <<endl;
}

int BubbleSort(int *A,int N){
	int count=0;
	int flag=1;
	int j;
	while (flag){
		flag=0;
		for(j=N-1;j>=1;j--){
			if (A[j]<A[j-1]){
				std::swap(A[j],A[j-1]);
				flag=1;
				count++;
			}
		}
	}
	out(A,N);
	return count;
}

int main(){
	int N,count;
	cin >> N;
	int i;
	int A[N];
	for (i=0;i<=N-1;i++){
		cin >> A[i];
	}
	count=BubbleSort(A,N);
	cout << count <<endl;
	return 0;
}
