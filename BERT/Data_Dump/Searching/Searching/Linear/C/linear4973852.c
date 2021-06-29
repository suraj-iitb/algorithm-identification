#include<stdio.h>

int main(void)
{
	int n,q,j;
	int i,b,a=0;
	
	scanf("%d",&n);
	
	int S[n];
	
	for(i=0;i<n;i++){
		scanf("%d",&S[i]);
	}
	
	scanf("%d",&q);
	
	for(j=0;j<q;j++){
		scanf("%d",&b);
		for(i=0;i<n;i++){
			if(S[i]==b){
				a++;
				break;
			}
		}
	}
	
	printf("%d\n",a);
	return 0;
}


