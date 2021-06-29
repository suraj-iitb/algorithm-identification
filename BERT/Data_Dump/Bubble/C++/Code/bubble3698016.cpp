#include<cstdio>
#include<iostream>
using namespace std;
const int maxn = 101;
int N;
int A[maxn];

int main(){
	cin >> N;
	for(int i = 0;i < N;i++){
		cin >> A[i];
	}
	getchar();
	int i,j;
	int count = 0;
	
	for(i = 0;i < N;i++){
		for(j = 0;j < N - i - 1;j++){
			if(A[j] > A[j + 1]){
				int temp = A[j];
				A[j] = A[j + 1];
				A[j + 1] = temp;
				count++;
			}
		}		
//		for(int i = 0;i < N - 1;i++){
//			cout << A[i] << " "; 
//		}
//		cout << A[N - 1];
//		cout << endl; 
	}
	for(i = 0;i < N - 1;i++)cout << A[i] <<" ";
	cout << A[N - 1] << endl;
	cout << count << endl; 
}
