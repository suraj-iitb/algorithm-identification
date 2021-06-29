#include<stdio.h>
int main(void)
{

	int num,i,n,j,v,A[100];


	scanf("%d",&num);


	for(i=0;i<=num-1;i++)
		scanf("%d",&A[i]);

	for(n=0;n<=num-1;n++){
			if (n==num-1)printf("%d\n",A[n]);
			else  printf("%d ",A[n]);
		}

	for(i=1;i<=num-1;i++){
		v=A[i];
		j=i-1;
		while(j>=0 && A[j]>v){
			A[j+1]=A[j];
			j--;
			A[j+1]=v;
		}
		

		for(n=0;n<=num-1;n++){
			if (n==num-1)printf("%d\n",A[n]);
			else printf("%d ",A[n]);
		}

	}

	return(0);
}
