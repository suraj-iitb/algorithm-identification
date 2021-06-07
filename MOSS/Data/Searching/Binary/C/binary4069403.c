#include<stdio.h>

int main(){
	int A[100000];
	int i,n,j,key,ans=0,light,right,mid;	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&A[i]);
	scanf("%d",&j);
	for(i=0;i<j;i++){
		scanf("%d",&key);

		light=0;	right=n;
		while(right-light>1){
			mid=(light+right)/2;

			if(key<A[mid])right=mid;
			else light=mid;
		}
		if(key==A[light])ans++;

	}
	printf("%d\n",ans);
	return 0;
}

