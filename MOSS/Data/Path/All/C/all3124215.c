#include<cstdio>
#include<functional>
#include<algorithm>
#define MM 2000000000
using namespace std;
int main(void)
{
	int v,e,i,j,k,a[100][100],s,t,d,flg;
	scanf("%d %d",&v,&e);
	for(i=0;i<v;i++)	{
		for(j=0;j<v;j++)	{
			if(i==j)	a[i][j]=0;
			else a[i][j]=MM;
		}
	}
	for(i=0;i<e;i++)	{
		scanf("%d %d %d",&s,&t,&d);
		a[s][t]=d;
	}
	
/*		for(i=0;i<v;i++)	{
			if(a[i][0]==MM)	printf("INF");
			else printf("%d",a[i][0]);
			for(j=1;j<v;j++)	{
				if(a[i][j]==MM)	printf(" INF");
				else printf(" %d",a[i][j]);	
			}
			printf("\n");
		}
*/	
	
	
	
	
	for(k=0;k<v;k++)	{
		for(i=0;i<v;i++)	{
			for(j=0;j<v;j++)	{
				if(a[i][k]!=MM && a[k][j]!=MM)	{
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
				}
			}
		}
	}
	flg=1;
	for(i=0;i<v;i++)	{
		if(a[i][i]<0)	{
			flg=0;	break;
		}
	}
	if(flg==0)	printf("NEGATIVE CYCLE\n");
	else {
		for(i=0;i<v;i++)	{
			if(a[i][0]==MM)	printf("INF");
			else printf("%d",a[i][0]);
			for(j=1;j<v;j++)	{
				if(a[i][j]==MM)	printf(" INF");
				else printf(" %d",a[i][j]);	
			}
			printf("\n");
		}
	}
	return 0;
}
