#include<stdio.h>
int main(){
	int i,n,N[10000],b,count=0,flag=1;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&N[i]);
	}
	while(flag){
		flag=0;
		for(i=n-1;i>=0;i--){
			if(N[i]<N[i-1]){
				b=N[i];
				N[i]=N[i-1];
				N[i-1]=b;
				count++;
				flag=1;
			}
		}
	}
	for(i=0;i<n-1;i++){
		printf("%d ",N[i]);
	}
	printf("%d\n",N[n-1]);
	printf("%d\n",count);
	return 0;
}
