#include<stdio.h>
#include<stdlib.h>
typedef struct A{char m;int n,f;}A;
A D[100005];
int N,i,flg=0;
void sw(A *a,A *b)
{
	A c=*a;
	*a=*b;
	*b=c;
}

int pt(int p,int r)
{
	int i,j,pos;
	A x;
	x=D[r];
	i=p-1;
	for(j=p;j<r;j++)
	{
		if(D[j].n<=x.n)
		{
			sw(&D[++i],&D[j]);
		}
	}
	sw(&D[i+1],&D[r]);
	return i+1;
}

void qs(int p,int r)
{
	int q;
	if(p<r)
	{
		q=pt(p,r);
		qs(p,q-1);
		qs(q+1,r);
	}
}


int main()
{
	scanf("%d\n",&N);
	for(i=1;i<=N;i++)
	{
		scanf("%c %d\n",&D[i].m,&D[i].n);
		D[i].f=i;
	}
		
	qs(1,N);
	for(i=2;i<=N;i++)
		if(D[i-1].n==D[i].n&&D[i-1].f>D[i].f)
			flg=1;
	puts(flg?"Not stable":"Stable");
	for(i=1;i<=N;i++)
		printf("%c %d\n",D[i].m,D[i].n);
	return 0;
}
