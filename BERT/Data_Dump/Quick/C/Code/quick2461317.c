#include <stdio.h>
#define N 100000
#define F 0
#define T 1
 
typedef struct {
  char c;
  int value;
  int id;
} cards;
 
cards A[N];
 
int partition(int , int );
 
void qSort(int , int );
 
int isStable(int ); 
 
int main() {
  int n, i;
 
  scanf("%d", &n);
  
  for(i = 0;i < n;i ++)
    {
      scanf("%s %d", &A[i].c, &A[i].value);

      A[i].id = i;
    }
 
  qSort(0, n-1);
 
  if(isStable(n) == F)printf("Not stable\n");

  else printf("Stable\n");

  for (i = 0;i < n; i ++ )
    {
      printf("%c %d\n", A[i].c, A[i].value);
    }
  return 0;
 
}

int partition(int p, int r) {

  int i, j, x;
  cards tmp;
 
  x = A[r].value;

  i = p-1;

  for (j = p;j < r;j ++)
    {
      if(A[j].value <= x)
	{
	  i++;
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
 
void qSort(int p, int r) {
  int q;
  
  if (p < r)
    {
      q = partition(p, r);
      qSort(p, q-1);
      qSort(q+1, r);
    }
}
 
int isStable(int n) {
  int i;

  for(i = 0;i < n-1;i ++)
    {
      if(A[i].value == A[i+1].value && A[i].id > A[i+1].id)return F;
    }
  return T;
}
