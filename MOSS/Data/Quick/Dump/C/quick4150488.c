#include<stdio.h>

#define LIM 100000
#define EX 2000000000

typedef struct card{
  char pic;
  int num;
}card;

void merge(card *,int,int,int,int);
void mergesort(card *,int,int,int);
int partition(card *,int,int,int);
void quicksort(card *,int,int,int);

card Lef[LIM/2+2],Rig[LIM/2+2];

void merge(card *A,int n,int left,int mid,int right)
{
  int i,j,k;
  int a = mid -left;
  int b = right - mid;
  for(i=0;i<a;i++)
    Lef[i] = A[left+i];
  for(i=0;i<b;i++)
    Rig[i] = A[mid+i];
  Lef[a].num = Rig[b].num = EX;
  i = j = 0;
  for(k = left;k<right;k++) {
    if(Lef[i].num <= Rig[j].num) {
      A[k] = Lef[i++];
    }else{
      A[k] = Rig[j++];
    }
  }
}

void mergesort(card *A,int n,int left,int right)
{
  int mid;
  if(left+1 < right) {
    mid = (left + right) / 2;
    mergesort(A,n,left,mid);
    mergesort(A,n,mid,right);
    merge(A,n,left,mid,right);
  }
}

int partition(card *A,int n,int p,int r)
{
  int i,j;
  card t,x;

  x = A[r];
  i = p-1;

  for(j=p;j<r;j++){
    if(A[j].num <= x.num) {
      i++;
      t = A[i];
      A[i] = A[j];
      A[j] = t;
    }
  }

  t = A[i+1];
  A[i+1] = A[r];
  A[r] = t;

  return i+1;
}

void quicksort(card *A,int n,int p,int r)
{
  int x;
  if(p < r) {
    x = partition(A,n,p,r);
    quicksort(A,n,p,x-1);
    quicksort(A,n,x+1,r);
  }
}

int main()
{
  int n,N,i;
  card A[LIM],B[LIM];
  char C[10];
  int judge = 1;

  scanf("%d",&n);

  for(i=0;i<n;i++) {
    scanf("%s%d",C,&N);
    A[i].pic = B[i].pic = C[0];
    A[i].num = B[i].num = N;
  }

  mergesort(A,n,0,n);
  quicksort(B,n,0,n-1);

  for(i=0;i<n;i++) {
    if(A[i].pic != B[i].pic)
      judge = 0;
  }

  if(judge == 1)
    printf("Stable\n");
  else
    printf("Not stable\n");

  for(i=0;i<n;i++) {
    printf("%c %d\n",B[i].pic,B[i].num);
  }

  return 0;
}

