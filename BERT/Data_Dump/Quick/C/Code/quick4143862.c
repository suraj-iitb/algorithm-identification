#include<stdio.h>
#include<stdlib.h>
#define MAX 100000

struct card
{
  char suit[2];
  int num;
  int order; // 順序
};

int partition(struct card *,int,int);
void quicksort(struct card *,int,int);

int main()
{
  struct card C[MAX];
  int n;
  int i;
  int flag=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%s%d", C[i].suit, &C[i].num);
      C[i].order=i+1;
    }

  quicksort(C,0,n - 1);

  for(i=0;i<n;i++)
    {
      if(C[i].order>C[i+1].order && C[i].num==C[i+1].num)
	{
	  flag++;
	  break;
	}
    }

  if(flag==0) printf("Stable\n");
  else printf("Not stable\n");

  for(i=0;i<n;i++) printf("%s %d\n",C[i].suit, C[i].num);

  return 0;
}

int partition(struct card *C, int p, int r)
{
  int i, j, a;
  struct card x;

  a=C[r].num;
  i=p-1;

  for(j=p;j<r;j++)
    {
      if(C[j].num<=a)
	{
	  i++;
	  x=C[i];
	  C[i]=C[j];
	  C[j]=x;
	}
    }

  x=C[i+1];
  C[i+1]=C[r];
  C[r]=x;

  return i+1;
}

void quicksort(struct card *C, int p, int r)
{
  int q;
  if(p<r)
    {
      q = partition(C,p,r);
      quicksort(C,p,q-1);
      quicksort(C,q+1,r);
    }
}

