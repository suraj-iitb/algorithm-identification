#include<stdio.h>

int main(void)
{
	int n,q,i,j,count=0;
	
	scanf("%d",&n);
	
	int s[n];
	
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	
	scanf("%d",&q);
	
	int t[q];
	
	for(i=0;i<q;i++){
		scanf("%d",&t[i]);
	}
	
	for(i=0;i<q;i++){
		for(j=0;j<n;j++){
			if(t[i] == s[j]){ 
				count++;
				break;
			}
		}
	}
	
	printf("%d\n",count);
	
	return 0;
}
