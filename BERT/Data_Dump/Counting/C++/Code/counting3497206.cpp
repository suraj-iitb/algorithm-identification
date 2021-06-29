#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <set>
#include <utility>
#include <cstdio>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n, m) for (int i = n; i >= m; i--)

int A[2000001]={0}, B[2000001];
int n;

void counting_sort(int k){
	int C[10001] = {0};
	rep(i, n){
		C[A[i]]++;
		
	}
	

	rep(i, k){
		C[i+1] = C[i] + C[i+1];
		
	}
	
	rrep(i, n-1, 0){
		B[C[A[i]]] = A[i];
		// rep(i, n) printf("C%d ", C[i]);
		// rep(i, n) printf("%d ", B[i]);
		// printf(" A[%d] %d\n", i, A[i]);
		
		C[A[i]]--;
	}
	// printf("\n");
	

}

int main(){

	scanf("%d", &n);
	rep(i, n) scanf("%d", &A[i]);
	counting_sort(10000);
	for(int i = 1; i <= n; i++){
		if(i > 1) printf(" ");

		printf("%d", B[i]);
	}
	printf("\n");
}
