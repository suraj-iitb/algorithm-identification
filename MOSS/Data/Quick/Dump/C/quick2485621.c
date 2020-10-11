#include <stdio.h>
#include <stdlib.h>
 
#define MAX 100000
 
typedef struct{
  char suit;
  int num,id;
} Card;
 
void quickSort(Card [], int, int);
int partition(Card [], int, int);
 
int main()
{
  Card A[MAX],B[MAX];
  int i,j,s,flag=0,n;
 
  scanf("%d",&n);
 
  for(i=0 ; i<n ; i++)
    {
      scanf("%s %d",&A[i].suit, &A[i].num);
      A[i].id = i;
      B[i] = A[i];
    }
 
  quickSort(A,0,n-1);
 
  for(i=0 ; i<n-1 ; i++)
    {
      if(A[i].num == A[i+1].num)
    {
      if(A[i].id > A[i+1].id) flag = 1;
    }
    }
 
  if( flag == 0) printf("Stable\n");
  else printf("Not stable\n");
 
  for(i=0 ; i<n ; i++)
    {
      printf("%c %d\n",A[i].suit, A[i].num);
    }
 
  return 0;
}
 
void quickSort(Card A[],int p, int r)
{
  int q;
 
  if(p < r)
    {
      q = partition(A, p, r);
      quickSort(A, p, q-1);
      quickSort(A, q+1, r);
    }
}
 
 

int partition(Card *A, int p, int r)
{
  Card tmp;
  int x,i,j;
 
  x = A[r].num;
  i = p-1;
 
  for( j=p ; j<=r-1 ; j++ )
    {
      if( A[j].num <= x )
    {
      i = i + 1;
      tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }  
    }
 
  tmp = A[i+1];
  A[i+1] = A[r];
  A[r] = tmp;
 
  return i+1;
}
