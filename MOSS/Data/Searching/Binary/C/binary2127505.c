#include<stdio.h>
#include<stdlib.h>
#define centering center=(right-left)/2+left
main(){
	int i,j,s,q,t,sum,left,right,center;
	int n[100000],m[50000];
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
		left=0;right=s-1;
		while(left<=right){
			centering;
			if(m[j]==n[center]){
				sum++;break;
			}else{
			if(m[j]<n[center]){
				right=center-1;
			}else{
			if(m[j]>n[center]){
				left=center+1;
			}}}
		}
	}
	printf("%d\n",sum);
	return 0;
}
