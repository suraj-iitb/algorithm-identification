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
	
	int i,j;
	int count = 0;
	for(i = 0;i < N;i++){
		int min_num = A[i];
		int pos = i;
		for(j = i;j < N;j++){
			if(min_num > A[j]){
				min_num = A[j];
				pos = j;
			}
		}
		if(pos != i){
			int temp = A[i];
			A[i] = A[pos];
			A[pos] = temp;
			count++;
		}
	
	}
	
	for(i = 0;i < N - 1;i++)cout << A[i] <<" ";
	cout << A[N - 1] << endl;
	cout << count << endl;
	
}
