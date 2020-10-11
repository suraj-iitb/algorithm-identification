#include <stdio.h>

#define maxN 100

void bubble(int N,int A[]){
	int c,tmp,swc=0;
	int flag = 1;
	while(flag){
		flag = 0;
		for(c=N-1;c>=1;c--){
			if(A[c]<A[c-1]){
				tmp = A[c];
				A[c] = A[c-1];
				A[c-1] = tmp;
				swc++;
				flag = 1;
			}
		}
	}
	for(c=0;c<N;c++){
		printf("%d",A[c]);
		if(c < N-1){
			printf(" ");
		}
	}
	printf("\n%d\n",swc);
}

int main(void){
	int c,n,a[maxN];
	scanf("%d",&n);
	for(c=0;c<n;c++){
		scanf("%d",&a[c]);
	}
	bubble(n,a);
}
