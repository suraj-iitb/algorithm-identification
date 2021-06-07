#include <stdio.h>

int linearSearch(int A[], int n, int key);



int main()
{
  
  int i;
  int n;
  int q;
  int A[10000+1];
  int key;
  int kei = 0;

  scanf("%d",&n);
  for( i = 0 ; i < n; i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&q);
  for( i = 0; i < q; i++){
    scanf("%d",&key);
    if(linearSearch(A,n,key))kei++;
    
  }
  printf("%d\n",kei);

  return 0;
    
}


int linearSearch( int A[], int n, int key)
{

  int i = 0;
  A[n] = key;
  while( A[i] != key)
    i++;
  return i!=n;
  
}

