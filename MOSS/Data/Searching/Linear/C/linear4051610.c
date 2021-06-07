#include <stdio.h>
#define M 10000

int linearSearch(int [ ], int , int );

int main (){
	int n, S[M],q,i,fact;
	int count = 0;
	scanf("%d",&n);
	for(i = 0; i < n ; i++){
		scanf("%d",&S[i]);
	}
	scanf("%d",&q);
	for(i = 0; i < q ; i++){
		scanf("%d",&fact);
		if( linearSearch(S,n,fact)) count++;
	}
	printf("%d\n",count);
}

int linearSearch(int R[ ],int n,int x) {
int i;
	for(i = 0; i < n; i++){
		if(R[i] ==  x) {
			return 1;
			}
	}
	return 0;
}
