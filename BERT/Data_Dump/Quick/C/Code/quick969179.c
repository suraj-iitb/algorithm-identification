#include <stdio.h>
typedef struct {
  char mark;
  int num;
  int prev;
} Card;
int Partition(Card *,int,int);
void QuickSort(Card *,int ,int);
int Stable(Card *,int);
int main()
{
  Card A[100001];
  int i,n,a=0;
  scanf("%d ",&n);
  //printf("%d\n",n);
  for(i=1;i<=n;i++)
    {
      scanf("%c%d ",&A[i].mark,&A[i].num);
      A[i].prev = a++;
      // printf("%c %d %d\n",A[i].mark,A[i].num,A[i].prev);
    }
  QuickSort(A,1,n);
  if(Stable(A,n)==0) printf("Stable\n");
  else printf("Not stable\n");
  for(i=1;i<=n;i++)
    {
      printf("%c %d\n",A[i].mark,A[i].num);
    }
  return 0;
}
int Partition (Card *A,int p,int r)
{
  int x,i,j;
  Card temp;
  x=A[r].num;
  i=p-1;
  for(j=p;j<r;j++)
    {
      if(A[j].num<=x)
	{
	  i++;
	  temp.mark=A[i].mark;
	  temp.num=A[i].num;
	  temp.prev=A[i].prev;
	  A[i].mark=A[j].mark;
	  A[i].num=A[j].num;
	  A[i].prev=A[j].prev;
	  A[j].mark=temp.mark;
	  A[j].num=temp.num;
	  A[j].prev=temp.prev;
	}
    }
  temp.mark=A[i+1].mark;
  temp.num=A[i+1].num;
  temp.prev=A[i+1].prev;
  A[i+1].mark=A[r].mark;
  A[i+1].num=A[r].num;
  A[i+1].prev=A[r].prev;
  A[r].mark=temp.mark;
  A[r].num=temp.num;
  A[r].prev=temp.prev;
  return i+1;
}
void QuickSort(Card *A,int p,int r)
{
  int q;
  if(p<r)
    {
      q = Partition(A,p,r);
      QuickSort(A,p,q-1);
      QuickSort(A,q+1,r);
    }
}
int Stable(Card *A,int n)
{
  int i;
  for(i=1;i<n;i++)
    {
      if(A[i].num == A[i+1].num)
	{
	  // printf("%c %d %d\n",A[i].mark,A[i].num,A[i].prev);
	  //printf("%c %d %d\n",A[i+1].mark,A[i+1].num,A[i+1].prev);
	  if(A[i].prev >A[i+1].prev) return 1;
	}
    }
  return 0;
}
