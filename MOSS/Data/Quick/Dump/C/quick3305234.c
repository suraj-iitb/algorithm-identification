#include<stdio.h>

#define MAX 100000

typedef struct{
  char mark;
  int number;
}card;

int partition(card *,int,int);
void quicksort(card *,int,int);
int Stable(card *,card *,int);

int main()
{
  int n,i;
  card A[MAX],in[MAX];

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++)
    {
      scanf(" %c %d",&A[i].mark,&A[i].number);
      in[i] = A[i];
    }
  
  quicksort(A,0,n-1);
  
  if(Stable(in,A,n)) printf("Stable\n");
  else printf("Not stable\n");

  for(i = 0 ; i < n ; i++)
    {    
      printf("%c %d\n",A[i].mark,A[i].number);
    }
  
  return 0;
}

int partition(card *A,int p,int r)
{
  int x,i,j;
  card change;

  x = A[r].number;

  i = p-1;

  for(j = p ; j < r ; j++)
    {
      if(A[j].number <= x)
	{
	  i++;
	  change = A[i];
	  A[i] = A[j];
	  A[j] = change;
	}
    }
  change = A[i+1];
  A[i+1] = A[r];
  A[r] = change;

  return i+1;
}

void quicksort(card *A,int p,int r)
{
  int q;
  if(p < r)
    {
      q = partition(A,p,r);
      quicksort(A,p,q-1);
      quicksort(A,q+1,r);
    }
  return;
}

int Stable(card *in,card *out,int n)
{
  int i,j,a,b;

  for(i = 0 ; i < n-1 ; i++)
    {
      for(a = 0 ; a < n ; a++)
	{
	  if(out[i].number == out[i+1].number)
	    {
	      if(in[a].number == out[i].number)
		{
		  if(in[a].mark == out[i].mark)
		    {
		      in[a].number = -1;
		      break;
		    }
		  else return 0;
		}
	    }
	}
    
    }
  return 1;
}

