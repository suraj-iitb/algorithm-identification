#include <stdio.h>
#include <stdlib.h>

int main(void){
	int n,q,i,j,s[10000],key,res=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	scanf("%d",&q);
	for(j=0;j<q;j++){
		scanf("%d",&key);
		for(i=0;i<n;i++){
			if(s[i] == key){
				res++;
				break;
			}
		}
	}
	printf("%d\n",res);
	return 0;
}
