#include<stdio.h>

int main(){

	int i,n,q,s[10000+1],t,c=0,k;

	scanf("%d",&n);

	for(i=0;i<n;i++)
		scanf("%d",&s[i]);

	scanf("%d",&q);

	for(i=0;i<q;i++){
		scanf("%d",&t);
		//seach
		s[n]=t;
		k=0;
		while(s[k]!=t){
			k++;
		}
		if(k!=n)
			c++;
		
	}
	printf("%d\n",c);

	return 0;
	
}

