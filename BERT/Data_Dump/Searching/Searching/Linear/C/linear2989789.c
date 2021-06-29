#include <stdio.h>
int main(){
	int q,t[500],i,j=0,cnt=0,s[10000],n;
	
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",&s[i]);

	scanf("%d",&q);
	for(i=0;i<q;i++) scanf("%d",&t[i]);
	
/*	for(i=0;i<q;i++){
		while(s[j]!=t[i]) j++;
		if(j!=n) cnt++;	
	}
	*/
	for(i=0;i<q;i++){
		for(j=0;j<n;j++){
			if(s[j]==t[i]){
				cnt++;
				break;
			}
		}
	}

	printf("%d\n",cnt);
	
	return 0;
}

