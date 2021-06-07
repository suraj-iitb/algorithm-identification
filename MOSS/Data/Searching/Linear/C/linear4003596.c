#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int n=0, m=0, i=0, j=0, count=0;
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++){ scanf("%d", &a[i]); }
	
	scanf("%d", &m);
	int b[m];
	for(i=0; i<m; i++){ 
		scanf("%d", &b[i]);
		for(j=0; j<n; j++)
		{
			if(a[j]==b[i]){
				count++;
				break;
			}
		}
	}
	printf("%d\n", count);

	return 0;
}

