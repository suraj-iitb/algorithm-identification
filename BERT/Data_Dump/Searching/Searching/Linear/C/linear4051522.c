#include<stdio.h>

int linear(int *,int,int);
int main(){
	int i,j,n,q[100000],sum=0,s,t;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&q[i]);
	}
	scanf("%d",&s);
	for(i=0;i<s;i++){
		scanf("%d",&t);
		sum+=linear(q,n,t);
	}
	printf("%d\n",sum);
	return 0;
}

int linear(int *q,int n,int t){
	int j=0;
	q[n]=t;
	while(q[j]!=t){
		j++;
	}
	if(j==n)return 0;
	return 1;
}
