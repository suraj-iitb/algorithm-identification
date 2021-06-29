#include<stdio.h>
#include<stdlib.h>
typedef struct A{char m;int n,f;}A;
A KJ[100005];
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
	x=KJ[r];
	i=p-1;
	for(j=p;j<r;j++)
	{
		if(KJ[j].n<=x.n)
		{
			sw(&KJ[++i],&KJ[j]);
		}
	}
	sw(&KJ[i+1],&KJ[r]);
	return i+1;
}

void ko(int p,int r)
{
	int q;
	if(p<r)
	{
		q=pt(p,r);
		ko(p,q-1);
		ko(q+1,r);
	}
}


int main(){
  
	scanf("%d\n",&N);
	for(i=1;i<=N;i++){
	  
		scanf("%c %d\n",&KJ[i].m,&KJ[i].n);
		KJ[i].f=i;
	}
		
	ko(1,N);
	for(i=2;i<=N;i++)
		if(KJ[i-1].n==KJ[i].n&&KJ[i-1].f>KJ[i].f)
			flg=1;
	puts(flg?"Not stable":"Stable");
	for(i=1;i<=N;i++)
		printf("%c %d\n",KJ[i].m,KJ[i].n);
	return 0;
}

