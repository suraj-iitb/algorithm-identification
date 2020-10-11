#include <stdio.h>

#define AIMAX 10000

int main(void)
{
	int i, j, n, a, cnt, flag=0;
	int C[AIMAX+1]={0};
	
	scanf("%d",&n);
	for(i=0; i<n; i++) {
		scanf("%d",&a);
		C[a]++;
	}
	
	for (i=0; i<=AIMAX; i++) {
		cnt = C[i];
		for (j=0; j<cnt; j++) {
			if(flag) printf(" ");
			else flag = 1;
			printf("%d",i);
		}
	}
	printf("\n");
	
	return 0;
}
