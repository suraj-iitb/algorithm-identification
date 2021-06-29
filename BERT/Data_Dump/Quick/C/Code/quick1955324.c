#include<stdio.h>

typedef struct { 
int a;
char c;
}Card;

Card A[100003],B[100003];
  
int partition(int,int);
void quickSort(int,int);

void merge(int,int,int);
void mergeSort(int,int);

int main(){
  int n,r,i,judge=0;

  scanf("%d",&n);

  for( i = 0 ; i < n ; i++ ){
    scanf("%s",&A[i].c);
    scanf("%d",&A[i].a);
    B[i] = A[i];
  }

  quickSort(0,n-1);
  mergeSort(0,n);

  for( i = 0 ; i < n ; i++ ){
    if( A[i].a != B[i].a || A[i].c != B[i].c ){
      judge = 1;
      break;
    }
  }

  if( judge == 1 ) printf("Not stable\n");
  else printf("Stable\n");

  for( i = 0 ; i < n ; i++ ){
    printf("%c %d\n",A[i].c,A[i].a);
  }
  
  return 0;
}


void quickSort(int p,int r){
  int q;
  if( p < r ){
    q = partition(p,r);
  quickSort(p,q-1);
  quickSort(q+1,r);
  }
}

int partition(int p,int r){
  int i,j,x;
  Card temp;
  x = A[r].a;
  i = p-1;
  for( j = p ; j < r ; j++ ){
    if( A[j].a <= x ){
      i = i + 1;
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

void merge(int left,int mid,int right)
{
  int n1 = mid - left;
  int n2 = right - mid;
  Card L[n1+1],R[n2+1];
  int i,j,k;

  for( i = 0 ; i < n1 ; i++ )
    L[i] = B[left+i];
  for(i = 0 ; i < n2 ; i++ )
    R[i] = B[mid+i];
  L[n1].a = 1000000005;
  R[n2].a = 1000000005;
  i = 0;
  j = 0;
  for( k = left ; k < right ; k++ )
    {
      if(L[i].a <= R[j].a){
	B[k] = L[i];
	i = i + 1;
      }
      else
	{
	  B[k] = R[j];
	  j = j + 1;
	}
    }
}

void mergeSort(int left,int right)
{
  int mid;

  if( left+1 < right )
    {
      mid = (left+right)/2;
      mergeSort(left,mid);
      mergeSort(mid,right);
      merge(left,mid,right);
    }

}
