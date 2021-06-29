#include<stdio.h>
int main(){
	int n,q,i,j,time=0;
	scanf("%d",&n);
	int s[n];
	for(i=0;i<n;i++)
	scanf("%d",&s[i]);
	scanf("%d",&q);
	int t[q];
	for(i=0;i<q;i++)
	scanf("%d",&t[i]);
	for(i=0;i<q;i++){
		j=0;
		s[n]=t[i];
		while(s[j]!=s[n])
		j++;
		if(j!=n)
		time++;
	}
	printf("%d\n",time);
	return 0;
} 
