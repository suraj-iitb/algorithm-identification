#include<stdio.h>

int n;
int A[200][200],t[200],a1[200],a2[200]; 

void bef(int x,int y)
{
	int i;
	int z=a1[x];
	if(z!=0)
	{
		for(i=1; i<=n;i++)
		{
			if(A[z][i]==1)
			{
				if(a2[i]==0)
				{
					y++;
					t[i]=t[z]+1;
					a1[y]=i;
					a2[i]=1;
				}
			}
		}
		bef(x+1,y);
	}
}






int main(void)
{
	int a,b,c,i,j;
	
	
	scanf("%d",&n);
	
	for(i=1; i<=n; i++)
	{
		t[i]=-1;
		a2[i]=0;
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
	
	t[1]=0;
	a1[1]=1;
	a2[1]=1;
	
	bef(1,1);
	
	for(i=1; i<=n; i++)
	{
		printf("%d %d\n",i,t[i]);
	}
	
	return 0;
}
