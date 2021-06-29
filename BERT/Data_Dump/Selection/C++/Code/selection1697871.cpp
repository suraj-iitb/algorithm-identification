#include<iostream>
using namespace std;

int out(int *A,int N){
	int i;
	for (i=0;i<=N-2;i++){
		cout << A[i] <<" ";
	}
	cout << A[N-1] <<endl;
}

int SelectionSort(int *A,int N){
	int i,j,minj,count=0;
	for (i=0;i<=N-1;i++){
		minj=i;
		for (j=i;j<=N-1;j++){
			if (A[minj]>A[j]){
				minj=j;
			}
		}
		if (i != minj){
			std::swap(A[i],A[minj]);
			count++;
		}
	}
	out(A,N);
	return count;
}

int main(){
	int N,count;
	cin >> N;
	int i,j;
	int A[N];
	for (i=0;i<=N-1;i++){
		cin >> A[i];
	}
	count=SelectionSort(A,N);
	cout << count <<endl;
	return 0;
}
