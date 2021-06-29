#include<stdio.h>
#define N 100
int main(){
	int n,i,j,min,hoge,a[N],cnt = 0;;
	scanf("%d",&n);
	for(i = 0; i < n; i++) scanf("%d",&a[i]);
	for(i = 0; i < n; i++){
		min = i;
		for(j = i; j < n; j++){
			if(a[j] < a[min]) min = j;
		}
		
			hoge = a[i];
			a[i] = a[min];
			a[min] = hoge;
			if(hoge != a[i]) cnt++;
		
	}
	for( i = 0; i < n; i++) {
		printf("%d",a[i]);
		if(i == (n-1) ) break;
		printf(" ");
	}
	printf("\n%d\n",cnt);
	return 0;
}

