#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define print(x) printf("%d",x)
#define scan(x) scanf("%d",&x)
#define printn(x) printf("%d\n",x)
#define rep(i,n,m) for(int i = n; i < m; i++)

int main(void){
	int a[100];
	int n;
	int count = 0;
	int minj;
	int ex;
	scan(n);
	rep(i,0,n){
		scan(a[i]);
	}
	
	rep(i,0,n){
		minj = i;
		rep(j,i,n){
			if(a[minj] > a[j]){
				minj = j;
			}
		}
		if(a[i] != a[minj]) count++;
		ex = a[minj];
		a[minj] = a[i];
		a[i] = ex;
	}

	rep(i,0,n){
		print(a[i]);
		if(i != n-1){
			printf(" ");
		}
	}
	printf("\n");
	printn(count);
	return 0;
}
