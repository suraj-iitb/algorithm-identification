#include<stdio.h>
#include<string.h>
#include<math.h>
#define anD &&
#define oR ||
#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
#define rep(i,n) for((i)=0;(i)<(n);(i)++)

void doswap(int*p,int *q,int *r) {
	int tmp;
	tmp = *p;
	*p = *q;
	*q = tmp;
	*r=*r+1 ;
}



int main(void) {
	int n, num = 0;
	scanf("%d", &n);
	int a[101] ;
	int i,j,mini;
	rep(i,n) {
		scanf("%d", &a[i]);
	}


	rep(i,n) {
		mini = i;
		for (j = i; j < n; j++) {
			if (a[mini] > a[j]) {
				mini = j;
			}
		}
		if(mini!=i)doswap(&a[i], &a[mini], &num);
	}
	rep(i,n) {
		if (i > 0) printf(" ");
		printf("%d", a[i]);
	}
	printf("\n%d\n", num);
	return 0;
}
