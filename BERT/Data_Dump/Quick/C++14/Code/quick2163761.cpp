#include<bits/stdc++.h>

using namespace std;

const int MAXN=100100;

struct data
{
	int num,ord;
	char c;
};

int split(data* A,int s,int t)
{
	int x=A[t].num;
	int i=s-1;
	for(int j=s;j<t;j++)
		if(A[j].num<=x)
			swap(A[j],A[++i]);
	swap(A[++i],A[t]);
	return i;
}

void Quick_Sort(data* A,int s,int t)
{
	if(s>=t) return ;
	int w=split(A,s,t);
	//printf("%d %d %d\n",s,w,t);
	Quick_Sort(A,s,w-1);
	Quick_Sort(A,w+1,t);
}

int cmp(const void* ta,const void* tb)
{
	data a=*(data*)ta,b=*(data*)tb;
	if(a.num!=b.num) return a.num-b.num;
	return a.ord-b.ord;
}

int main()
{
	int n;
	static data A[MAXN],B[MAXN];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s%d",&A[i].c,&A[i].num);
		B[i]=A[i];
		B[i].ord=i;
	}
	qsort(B,n,sizeof(data),cmp);
	Quick_Sort(A,0,n-1);
	bool flag=true;
	for(int i=0;i<n;i++)
		if(B[i].c!=A[i].c)
		{
			flag=false;
			break;
		}
	if(flag)
		printf("Stable\n");
	else
		printf("Not stable\n");
	for(int i=0;i<n;i++)
		printf("%c %d\n",A[i].c,A[i].num); 
	return 0;
}
