#include<bits/stdc++.h>
using namespace::std;

int n;

int main(){
	scanf("%d", &n);
	vector<int> A(n);
	for(int i = 0; i < n; i++) scanf("%d", &A[i]);
	int cnt = 0;
	for(int i = 0; i < n; i++){
		for(int j = n - 1; j >= i + 1; j--){
			if(A[j] < A[j - 1]){
				swap(A[j], A[j - 1]);
				cnt += 1;
			}
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d%c", A[i], " \n"[i + 1 == n]);
	}
	printf("%d\n", cnt);
	return 0;
}
