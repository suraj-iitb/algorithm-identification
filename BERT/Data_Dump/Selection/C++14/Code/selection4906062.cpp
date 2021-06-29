#include<bits/stdc++.h>
using namespace::std;

int n;

int main(){
	scanf("%d", &n);
	vector<int> A(n);
	for(int i = 0; i < n; i++) scanf("%d", &A[i]);
	int cnt = 0;
	for(int i = 0; i < n; i++){
		int mini = i;
		for(int j = i; j < n; j++){
			if(A[j] < A[mini]) mini = j;
		}
		if(i != mini){
			cnt += 1;
			swap(A[i], A[mini]);
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d%c", A[i], " \n"[i + 1 == n]);
	}
	printf("%d\n", cnt);
	return 0;
}
