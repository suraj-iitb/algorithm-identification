/*
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_2_A&lang=ja 
ALDS1_2_A:バブルソート
*/

#include <bits/stdc++.h>

using namespace std;

void disp(unsigned short int *n, unsigned short int N);

int main(void){

	unsigned short int N;
	scanf("%d", &N);

	unsigned short int n[N];

	for(int i=0; i<N; i++) {
		scanf("%d", &n[i]);
	}

    int max = N-1;
    int flag;
    if(N >= 2){
        flag = 1; //ソート終了フラグ
    }else if(N<=1) flag = 0;
    int count=0; //交換回数
    while(flag == 1){
        for(int i=0; i<max; i++){
            if(n[i] > n[i+1]){
                count += 1;
                unsigned short int tmp = n[i];
                n[i] = n[i+1];
                n[i+1] = tmp;
            }
        }
        max = max-1;
        if(max == 0) flag = 0;
    }

    disp(n, N);
    printf("%d\n",count);

	return 0;
	
  
}

void disp(unsigned short int *n, unsigned short int N){
	//printf("disp: ");
	for(int i=0; i<N; i++) {
		printf("%d", n[i]);
		if( i != N-1) printf(" ");
	}
	printf("\n");
}


