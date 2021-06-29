#include<iostream>
using namespace std;

void i_sort(int N,int *A);

int main(){
	int N;
	int A[100];
	cin >> N;
	for(int i = 0;i < N;i++){
		cin >> A[i];
		}
	i_sort(N,A);
}

void i_sort(int N,int *A){
	int temp = 0;
	int j = 0;
	for(int i = 0;i < N;i++){
		cout << A[i];
		
		if(i != N-1){
			 cout << " ";
			}else{
				cout << endl;
			}
	}
	for(int i = 1;i < N;i++){
		temp = A[i];
		j = i-1;
		while(j >= 0 && A[j] > temp){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = temp;
		for(int i = 0;i < N;i++){
			cout << A[i];
			if(i != N-1){
				 cout << " ";
				}else{
					cout << endl;
				}
		}
	}
}
