#include <stdio.h>
void mergesort(   long int [],  unsigned int,  unsigned int);
void merge(  long   int [],  unsigned int,  unsigned int,  unsigned int);

  unsigned int c =0, n ;
  long int l[260000], r[260000];

int main()
{
  unsigned int i ;   long   int s[500000];
  scanf("%d", &n);
  //printf("aaa%d\n",n);
  for( i = 0; i < n; i++){
    scanf("%ld" , &s[i]);
  }
  mergesort(s , 0 ,n );
  for ( i = 0; i < n; i++){
    printf("%ld", s[i]);
    if ( i != n-1){printf(" ");}
  }
  printf("\n%d\n",c);
  return 0;
}
void mergesort(   long  int a[] ,  unsigned int lef,  unsigned int rig){
    
  if ( lef +1 < rig){
      unsigned int mid = ( lef + rig)/2;
    mergesort( a , lef ,mid);
    mergesort(a , mid ,rig);
    merge (a ,lef ,mid ,rig);
  }
}
void merge (   long   int a[] ,   unsigned int lef ,   unsigned int mid ,  unsigned int rig){
  unsigned int k,none = mid - lef,i,j,ntwo = rig - mid;

  for (i = 0; i <  none;i++ ){
    l[i] = a[lef+ i];
  }
  for ( i = 0; i < ntwo ; i++){
    r[i] = a[mid + i];
  }l[none] = 2500000000;r[ntwo]= 2500000000; i= 0;j= 0;
  for (k = lef ;k < rig ;k++ ){
    c++;
    if (l[i] <= r[j]){
      a[k] = l[i];
      i = i + 1;
    }else{ 
      a[k] = r[j];
      j = j + 1;
    }
  }
}

