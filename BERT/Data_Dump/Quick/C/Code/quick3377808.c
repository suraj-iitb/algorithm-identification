#include <stdio.h>
#define MAX 100000
#define INFTY 114514810

typedef struct {
  char d;
  int f;
}CARD;

CARD A[MAX],B[MAX],L[MAX],R[MAX];

void quicksort(int,int);
int partition(int,int);
//void bubblesort(int);
void mergeSort(int,int);
void merge(int,int,int);

int main() {

  int n,i,flag=0;
  
  scanf("%d",&n);
  for(i = 0; i < n; i++) {
    scanf(" %c %d",&A[i].d,&A[i].f);
    B[i] = A[i];  
  }

  
  quicksort(0,n-1);
  //bubblesort(n);
  mergeSort(0,n);


  for(i = 0; i < n; i++) {
    if(A[i].d != B[i].d)
      flag = 1;
  }

  if(flag) printf("Not stable\n");
  else printf("Stable\n");
  
  for(i = 0; i < n; i++) {
    printf("%c %d\n",A[i].d,A[i].f);
  }

  /* for(i = 0; i < n; i++) {
     printf("%c %d\n",B[i].d,N[i].f);
     }
  
  */

  return 0;
}

void quicksort(int p,int r)
{
  int q;
  if(p < r) {
    q = partition(p,r);
    quicksort(p,q-1);
    quicksort(q+1,r);
  }
}

int partition(int p,int r)
{
  int x,i,j;
  CARD temp;
  x = A[r].f;
  i = p-1;
  for(j = p; j < r; j++) {
    if(A[j].f <= x) {
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

/*void bubblesort(int N)
{
  int i,j,flag;
  CARD temp;
  flag = 1;
  while(flag) {
    flag = 0;
    for(j = N-1; j > 0; j--) {
      if(B[j].f < B[j-1].f) {
	temp = B[j];
	B[j] = B[j-1];
	B[j-1] = temp;
	flag = 1;
      }      
    }
  }
}
*/

void mergeSort(int left,int right)
{
  int mid;
  if(left + 1 < right) {
    mid = (left + right)/2;
    mergeSort(left,mid);
    mergeSort(mid,right);
    merge(left,mid,right);
  } 
}

void merge(int left,int mid,int right)
{
  int n1,n2,i,j,k;
  n1 = mid - left;
  n2 = right - mid;

  for(i = 0; i < n1; i++) {
    L[i] = B[left + i];
  }
  for(i = 0; i < n2; i++) {
    R[i] = B[mid + i];
  }
  L[n1].f = INFTY;
  R[n2].f = INFTY;
  i = 0;
  j = 0;
  
  for(k = left; k < right; k++) {
    if(L[i].f <= R[j].f) {
      B[k] = L[i];
      i = i + 1;
    }
    else {
      B[k] = R[j];
      j = j + 1;
    }
}
}

