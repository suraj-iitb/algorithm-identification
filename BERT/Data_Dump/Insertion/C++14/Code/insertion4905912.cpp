#include<bits/stdc++.h>
using namespace::std;

int n;

int main(){
	scanf("%d", &n);
	vector<int> A(n);
	for(int i = 0; i < n; i++) scanf("%d", &A[i]);
	for(int j = 0; j < n; j++){
		printf("%d%c", A[j], " \n"[j + 1 == n]);
	}
	for(int i = 1; i < n; i++){
		int key = A[i];
		int j = i - 1;
		while(j >= 0 and A[j] > key){
			A[j + 1] = A[j];
			j -= 1;
		}
		A[j + 1] = key;
		for(int j = 0; j < n; j++){
			printf("%d%c", A[j], " \n"[j + 1 == n]);
		}
	}
	return 0;
}
