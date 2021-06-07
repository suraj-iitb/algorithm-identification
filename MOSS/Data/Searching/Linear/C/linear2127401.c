#include<stdio.h>
#include<stdlib.h>

main(){
	int i,j,s,q,t,sum;
	int n[10000],m[500];
	for(i=0;i<10000;i++){
		n[i]=0;
	}
	scanf("%d",&s);
	for(i=0;i<s;i++){
		scanf(" %d",&j);
		n[i]=j;
	}
	scanf(" %d",&t);
	for(i=0;i<t;i++){
		scanf(" %d",&j);
		m[i]=j;
	}
	sum=0;
	for(j=0;j<t;j++){
		for(i=0;i<s;i++){
			if(n[i]==m[j]){
				sum++;break;
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}
