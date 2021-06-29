#include <stdio.h>

#define MAX 100000
#define INFTY 2000000000

typedef struct{
  char mark;
  int value;
} Card;

void merge(Card *, int, int, int, int);
void mergeSort(Card *, int, int, int);
void quicksort(Card *, int, int);
int partition(Card *, int, int);

Card L[MAX], R[MAX];
int n, count=0;
 

int main()
{
  int i;
  Card A[MAX], a[MAX];
  int judge = 1;
  
  scanf("%d", &n);

  for( i = 0 ; i < n ; i++ ){
    scanf(" %c%d", &A[i].mark, &A[i].value);
    a[i] = A[i];
  }

  mergeSort(A, n, 0, n);
  quicksort(a, 0, n-1);

  for( i = 0 ; i < n ; i++ ) if( A[i].mark != a[i].mark ) judge = 0;
  
  if( judge == 1 ) printf("Stable\n");
  else printf("Not stable\n");
  
  for( i = 0 ; i < n ; i++ )
    printf("%c %d\n", a[i].mark, a[i].value);

  return 0;
}

void merge(Card S[], int n, int left, int mid, int right)
{
    int n1, n2, i, j, k;
    
    n1 = mid - left;
    n2 = right - mid;
    
    for( i = 0 ; i < n1 ; i++ ) L[i] = S[left+i];
    for( i = 0 ; i < n2 ; i++ ) R[i] = S[mid+i];
    
    L[n1].value = R[n2].value = INFTY;
    
    i = j = 0;
    
    for( k = left ; k < right ; k++ ){
        count++;
        if( L[i].value <= R[j].value ){
            S[k] = L[i];
            i++;
        }
        else {
            S[k] = R[j];
            j++;
        }
    }
}

void mergeSort(Card S[], int n, int left, int right)
{
    int mid;
    
    if( left+1 < right ){
        mid = (left + right)/2;
        mergeSort(S, n, left, mid);
        mergeSort(S, n, mid, right);
        merge(S, n, left, mid, right);
    }
}

void quicksort(Card A[], int p, int r)
{
  int q;

  if( p < r ){
    q = partition(A, p, r);
    quicksort(A, p, q-1);
    quicksort(A, q+1, r);
  }
}

int partition(Card A[], int p, int r)
{
  int i, j, x;
  Card tmp;
  
  x = A[r].value;
  i = p-1;
  
  for( j = p ; j < r ; j++ ){
    if( A[j].value <= x){
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
