#include<stdio.h>
int main(void)
{
	int a[100];
	int N,i,j,minj,x;
	int cunt=0;
	
	scanf("%d",&N);
	for(i=0;i<N;i++)scanf("%d",&a[i]);
	
	for(i=0;i<N-1;i++){
		minj=i;
		for(j=i;j<N;j++){
			if(a[j]<a[minj])minj=j;
		}
			x=a[i];
			a[i]=a[minj];
			a[minj]=x;
		if(i!=minj)cunt++;
	}
	for(i=0;i<N;i++){
		if(i>0)printf(" ");
		printf("%d",a[i]);
	}
	printf("\n%d\n",cunt);
	return 0;
}
