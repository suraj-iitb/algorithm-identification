#include<stdio.h>
#include<stdlib.h>
#define MAX 500000
#define INF 1000000000

void k_tmerge(int *,int,int,int);
void tmergesort(int *,int,int);

int count;


void tmergesort(int A[],int left,int right)
{
  int mid;
  if(left + 1 < right){
    mid = (left + right) / 2;
    tmergesort(A,left,mid);
    tmergesort(A,mid,right);
    k_tmerge(A,left,mid,right);
  }
}

void k_tmerge(int *A,int left,int mid,int right)
{
  int i,k,j,n1=0,n2=0;
  int *L,*R;

  n1 = mid - left;
  n2 = right - mid;

  L = (int *)malloc(sizeof(int)*(n1+1));
  R = (int *)malloc(sizeof(int)*(n2+1));

  for(i = 0;i <= n1-1;i++){
    L[i] = A[left + i];
  }

  for(j = 0;j <= n2-1;j++){
    R[j] = A[mid + j];
  }

  L[n1] = INF;
  R[n2] = INF;
  i = 0;
  j = 0;

  for(k = left;k <= right-1;k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
      count++;
    }
    else {
      A[k] = R[j];
      j++;
      count++;
    }
  }
  free(L);
  free(R);
}

int main()
{
  int n,i;
  int A[MAX];

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&A[i]);
  }
  tmergesort(A,0,n);

  for(i = 0;i < n;i++){
    if( i > 0 ) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}

