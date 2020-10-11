#include<stdio.h>
#define N 100
int main(){
	int i,j,n,flag,a[N],hoge,cnt = 0;
	scanf("%d",&n);
	for( i = 0; i < n; i++) scanf("%d",&a[i]);
	for(i = 0; i < n - 1; i++){
		flag = 1;
		while(flag == 1){
			flag = 0;
			for(j = n - 1; j > i; j--){
				if(a[j] < a[j - 1]){
					hoge = a[j];
					a[j] = a[j - 1];
					a[j - 1] = hoge;
					flag = 1;
					cnt++;
				}
			}
		}
	}
	for( i = 0; i < n; i++) {
		printf("%d",a[i]);
		if(i == (n-1) ) break;
		printf(" ");
	}
	printf("\n%d\n",cnt);
	return 0;
}
