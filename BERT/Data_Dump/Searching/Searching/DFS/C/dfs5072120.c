#include<stdio.h>

int A[200][200],a1[200],a2[200],a3[200];
int n,t;


void aa1(int a)
{
	int i;
	
	if(a2[a]==0 ){
		a1[a]=t;
		a2[a]=1;
	}

	for(i=1; i<=n; i++)
	{
		if(A[a][i]==1 && a2[i]==0)
		{	
			t++;
			aa1(i);
		}
	}
	
	if(a2[a]==1){
		t++;
		a3[a]=t;
		a2[a]=2;
	}
}

int main(void)
{
	int i,j;
	int a,b,c,s;
	
	scanf("%d",&n);
	
	for(i=1; i<=n; i++)
	{
		a2[i]=0;
		a3[i]=0;
		for(j=1; j<=n; j++)
		{
			A[i][j]=0;
		}
	}
	
	for(i=1; i<=n; i++)
	{
		scanf("%d %d",&a,&b);
		for(j=0; j<b; j++)
		{
			scanf("%d",&c);
			A[a][c]=1;
		}
	}
	
	t=1;
	aa1(1);
	for(i=1; i<=n; i++)
	{
		s=0;
		for(j=1; j<=n; j++)
		{
			s+=A[j][i];
		}
		if(s==0 && i!=1){
			t++;
			aa1(i);
		}
	}
	
	
	for(i=1; i<=n; i++)
	{
		printf("%d %d %d\n",i,a1[i],a3[i]);
	}
				
	return 0;
}
