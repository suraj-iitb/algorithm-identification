#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define print(x) printf("%d",x)
#define scan(x) scanf("%d",&x)
#define printn(x) printf("%d\n",x)
#define rep(i,n,m) for(int i = n; i < m; i++)

int main(void){
	int flag = 1;
	int i;
	int n;
	int ex;
	int a[100];
	int count = 0;
	scan(n);
	rep(i,0,n){
		scan(a[i]);
	}
	i = 0;
	while(flag){
		flag = 0;
		for(int j = n-1; j > i; j--){
			if(a[j] < a[j-1]){
				ex = a[j];
				a[j] = a[j-1];
				a[j-1] = ex;
				flag = 1;
				count++;
			}
		}
		i++;
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
