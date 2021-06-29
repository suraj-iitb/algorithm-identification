#include <stdio.h>

int linearSearch(int a[],int n,int key){
	int i = 0;
	a[n] = key;
	while(a[i] != key)i++;
	return i != n;
}

int main(void) {
	int A[10000+1];
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)scanf("%d",&A[i]);
	int q;
	int sum = 0;
	scanf("%d",&q);
	for(int i = 0;i < q; i++){
		int key;
		scanf("%d",&key);
		sum += linearSearch(A,n,key);
	}
	printf("%d\n",sum);
	return 0;
}

