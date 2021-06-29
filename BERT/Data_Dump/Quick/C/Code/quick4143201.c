#include<stdio.h>
#define MAX 100000
#define GUARD 1000000000
 
struct Card{
  char match;
  int value;
};

struct Card R[MAX / 2 + 2], L[MAX / 2 + 2];

void merge(struct Card A[], int n,int l, int m, int r)
{
  int i;
  int j;
  int k;
  int n1 = m - l;
  int n2 = r - m;

  for( i = 0 ; i < n1 ; i++ )L[i] = A[l+i];
  for( i = 0 ; i < n2 ; i++ )R[i] = A[m+i];
  L[n1].value = R[n2].value = GUARD;
  i = j = 0;
  for( k = l ; k < r ; k++ ){
    if( L[i].value <= R[j].value ){
      A[k] = L[i++];
    }
    else{
      A[k] = R[j++];
    }
  }
}

void mergesort(struct Card A[],int n,int l,int r)
{
  int m;

  if( l + 1 < r ){
    m = (l+r)/2;
    mergesort(A,n,l,m);
    mergesort(A,n,m,r);
    merge(A,n,l,m,r);
  }
}

int partition(struct Card A[], int n,int p, int r)
{
  int i;
  int j;
  struct Card change,b;
  b = A[r];
  i = p - 1;
  for( j = p; j < r; j++ ){
    if( A[j].value <= b.value ){
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

void quick(struct Card A[], int n, int p, int r)
{
  int q;

  if( p < r ){
    q = partition(A,n,p,r);
    quick(A,n,p,q-1);
    quick(A,n,q+1,r);
  }
}



int main()
{
  int n;
  int i;
  int w;
  struct Card A[MAX],B[MAX];
  char F[10];
  int stable = 1;

  scanf("%d",&n);
  for( i = 0 ; i < n; i++ ){
    scanf("%s%d",F,&w);
    A[i].match = B[i].match = F[0];
    A[i].value = B[i].value = w;
  }

  mergesort(A,n,0,n);
  quick(B,n,0,n-1);

  for( i = 0 ; i < n ; i++ ){
    if( A[i].match != B[i].match ) stable = 0;
  }

  if( stable == 1 )printf("Stable\n");
  else printf("Not stable\n");
  for( i = 0 ; i < n ; i++ ){
    printf("%c %d\n",B[i].match,B[i].value);
  }
  return 0;
}

  

