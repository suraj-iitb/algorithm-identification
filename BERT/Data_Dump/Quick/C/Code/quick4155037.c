#include<stdio.h>
#include<stdlib.h>
typedef struct A{char m;int n,f;}A;
A sum[100005];
int N,i,flg=0;
void num(A *a,A *b)
{
	A c=*a;
	*a=*b;
	*b=c;
}

int tum(int p,int r)
{
	int i,j,pos;
	A x;
	x=sum[r];
	i=p-1;
	for(j=p;j<r;j++)
	{
		if(sum[j].n<=x.n)
		{
			num(&sum[++i],&sum[j]);
		}
	}
	num(&sum[i+1],&sum[r]);
	return i+1;
}

void rum(int p,int r)
{
	int q;
	if(p<r)
	{
		q=tum(p,r);
		rum(p,q-1);
		rum(q+1,r);
	}
}


int main()
{
	scanf("%d\n",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%c %d\n",&sum[i].m,&sum[i].n);
		sum[i].f=i;
	}
		
	rum(1,N);
	for(i=2;i<=N;i++)
		if(sum[i-1].n==sum[i].n&&sum[i-1].f>sum[i].f)
			flg=1;
	puts(flg?"Not stable":"Stable");
	for(i=1;i<=N;i++)
		printf("%c %d\n",sum[i].m,sum[i].n);
	return 0;
}

