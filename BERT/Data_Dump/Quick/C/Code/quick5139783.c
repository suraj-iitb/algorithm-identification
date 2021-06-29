#include <stdio.h>
#include <stdlib.h>
#define N 1000000
typedef struct{
  char c[2];
  int num;
  int order;
}R;
int partition(R *A, int p, int r)
{
  int x;
  R keep[1];
  int i,j;
  x = A[r].num;
  i = p - 1;
  for(j = p; j < r; j++)
    {
      if(A[j].num <= x)
        {
          i++;
          keep[0] = A[j];
          A[j] = A[i];
          A[i] = keep[0];
        }
    }
  keep[0] = A[i+1];
  A[i+1] = A[r];
  A[r] = keep[0];
  return i+1;
}



void quickSort(R *A, int p, int r)
{
  int q;
  if(p < r){
    q = partition(A,p,r);
    quickSort(A,p,q-1);
    quickSort(A,q+1,r);
  }
  return;
}

int main()
{
  int n,i,r,p,x,j,flag = 0;
  char ch[2];
  R A[N];
  scanf("%d",&n);
  for(i = 0; i < n; i++)
    {
      scanf("%s%d",ch,&x);
      A[i].c[0] = ch[0];
      A[i].num = x;
      A[i].order = i;
    }
  p = 0;
  r = n-1;
  quickSort(A,p,r);
  
  
  for(i = 1; i < n; i++){
    if(A[i-1].num == A[i].num && A[i - 1].order > A[i].order)
        {
          flag += 1;
          break;
        }

  }
  if(flag == 0)
    printf("Stable\n");
  else printf("Not stable\n");
  for(i = 0; i < n; i++)
    printf("%s %d\n",A[i].c,A[i].num);

  return 0;
}


