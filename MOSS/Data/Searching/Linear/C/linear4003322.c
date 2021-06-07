#include <stdio.h>

int search(int A[], int n, int key){
	int i = 0;
	A[n] = key;
	while(A[i] != key){
	i++;
	}
	if(i != n)return 1;
	return 0;

}

int main(void){
	int i,n;
	int A[10001];
	int m, k;
	int sum = 0;
	
	scanf("%d",&n);
	for(i = 0; i < n;i++)
	{
		scanf("%d", &A[i]);
	}
	
	scanf("%d",&m);
	for(i = 0; i < m;i++)
	{
		scanf("%d", &k);
		if(search(A,n,k) == 1)sum++;
	}
	printf("%d\n",sum);
	return 0;
}
