#include <iostream>
using namespace std;

int a,key;

int main(){
	cin >> a;
	int A[a];
	for(int i=0; i<a; ++i){
		cin >> A[i];
	}
	
	for(int i=0; i<a-1; ++i){
		printf("%d ", A[i]);
	}
	printf("%d\n", A[a-1]);
	
	for(int i=1; i<a; ++i){
		key = A[i];
		int j = i-1;
		while(j>=0 && A[j] > key){
			A[j+1] = A[j];
			--j;
		}
		A[j+1] = key;
		
		for(int i=0; i<a-1; ++i){
			printf("%d ", A[i]);
		}
		printf("%d\n", A[a-1]);
	}
}
