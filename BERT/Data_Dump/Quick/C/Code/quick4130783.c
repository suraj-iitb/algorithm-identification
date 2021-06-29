#include<stdio.h>
#include<string.h>
#include<limits.h>

#define SIZE 100000

void quicksort(int, int);
int partition(int, int);
void merge(int, int, int);
void mergesort(int, int);

struct Card
{
  char suit;
  int num;
};

struct Card A[SIZE], B[SIZE];
  
int main()
{
  int i, n, num, s = 0;
  char suit;

  scanf("%d",&n);
  for(i = 0; i < n; i++)
    {
      scanf(" %c %d",&suit,&num);
      A[i].suit = B[i].suit = suit;
      A[i].num = B[i].num = num;
    }

  quicksort(0, n-1);
  mergesort(0, n);

  for(i = 0; i < n; i++)
    {
      if(A[i].suit != B[i].suit)s = 1;
    }

  if(s == 0)printf("Stable\n");
  else printf("Not stable\n");
  
  for(i = 0; i < n; i++)
    {
      printf("%c %d\n",A[i].suit,A[i].num);
    }

  return 0;
}

void quicksort(int p, int r)
{
  int q;
  
  if(p < r)
    {
      q = partition(p, r);
      quicksort(p, q-1);
       quicksort(q+1, r);
    }
}

int partition(int p, int r)
{
  int x, i, j;
  struct Card temp;
  
  x = A[r].num;
  i = p-1;
  
  for(j = p; j < r; j++)
    {
      if(A[j].num <= x)
	{
	  i++;
	  temp = A[i];
	  A[i] = A[j];
	  A[j] = temp;
	}
    }
  
  temp = A[i+1];
  A[i+1] = A[r];
  A[r] = temp;
  
  return i+1;
}

void merge(int left, int mid, int right)
{
  int i, j, k, n1, n2;
  struct Card L[SIZE/2+2], R[SIZE/2+2];

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0; i < n1; i++)
    {
      L[i] = B[left + i];
    }

  for(i = 0; i < n2; i++)
    {
      R[i] = B[mid + i];
    }

  L[n1].num = INT_MAX;
  R[n2].num = INT_MAX;

  i = 0;
  j = 0;

  for(k = left; k < right; k++)
    {
      if(L[i].num <= R[j].num)
	{
	  B[k] = L[i];
	  i++;
	}
      else
	{
	  B[k] = R[j];
	  j++;
	}
    }
}

void mergesort(int left, int right)
{
  int mid;
  
  if(left+1 < right)
    {
      mid = (left + right)/2;
      mergesort(left, mid);
      mergesort(mid, right);
      merge(left, mid, right);
    }
}

