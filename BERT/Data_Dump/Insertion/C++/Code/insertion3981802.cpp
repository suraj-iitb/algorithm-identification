/*
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_A&lang=ja

制約
	n≤20
	q≤200
	1≤Aの要素≤2,000
	1≤mi≤2,000

*/

#include <bits/stdc++.h>

using namespace std;

void disp(int *n, int N);

int main(void){

	int N;
	scanf("%d", &N);
	int n[N];

	for(int i=0; i<N; i++) scanf("%d", &n[i]);

	disp(n, N);

	for(int i=1; i<N; i++){
		int v = n[i];
		int j = i-1;
		while(j >=0 && n[j] > v){
			n[j+1] = n[j];
			j--;
		}
		//printf("i = %d, ", i);
		n[j+1] = v;
		disp(n, N);
	}
	//printf("\n");

	return 0;
	
  
}

void disp(int *n, int N){
	//printf("disp: ");
	for(int i=0; i<N; i++) {
		printf("%d", n[i]);
		if( i != N-1) printf(" ");
	}
	printf("\n");
}
