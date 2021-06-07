#include<stdio.h>

#define N 10000

int search(int s[],int n,int t){
	
	int i=0;
	s[n]=t;
	while(s[i]!=t)i++;
	
	return i!=n;

}

int main(void){
	
	int i,n,q,t,count;
	int s[N];
	
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&s[i]);
	}
	
	scanf("%d",&q);
	count=0;
	for(i=0;i<q;i++){
		scanf("%d",&t);
		if(search(s,n,t))count++;
	}
	
	printf("%d\n",count);

	return 0;
}

