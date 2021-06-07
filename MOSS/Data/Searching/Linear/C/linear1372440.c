#include <stdio.h>

#define DEF_ELEM_MAX 10001

int count=0;

int A[DEF_ELEM_MAX];
int n;

void Linear(int key)
{
	int k=0;
	A[n]=key;
	while(A[k] != key){
		k++;
	}

	if( k == n) return;

	count++;
	return ;
}

int main( void )
{
	int i;
	int j;
	int t;
	int q;

	scanf("%d",&n);

	for( i = 0; i < n; i++){
		scanf("%d", &A[i]);
	}

	scanf("%d",&q);
	for(j=0;j<q;j++){
		scanf("%d", &t);
		Linear(t);
	}

	printf("%d\n",count);
	return 0; 
}
