#include <stdio.h>
#include <stdlib.h>

int main(void){
	int *a,*b;
	int n,q,sum=0,i,o,sign;
	scanf("%d",&n);
	a = (int *)calloc(n+1,sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&q);
	b = (int *)calloc(q,sizeof(int));
	for(i=0;i<q;i++)
		scanf("%d",&b[i]);
	for(o=0;o<q;o++){
		i=0;sign=0;
		a[n] = b[o];
		while(a[i] != a[n]){
			i++;
		if(i == n){
			sign++;
			break;
		}
		}
		if(sign == 0)
			sum++;
		
	}
	printf("%d\n",sum);
	return 0;
	
}
