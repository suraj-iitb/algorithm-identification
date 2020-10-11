#include<stdio.h>
#include<stdlib.h>

#define NMAX 2000001

int c[NMAX],n;

void CountingSort(int *, int *, int);

int main(){

  int i,*a,*b,k=0;

  scanf("%d",&n);

  a = malloc(sizeof(int)*(n+1));
  b = malloc(sizeof(int)*(n+1));

  for(i = 1 ; i <= n ; i++){
    scanf("%d",&a[i]);
    if(k < a[i]) k = a[i];
  }

  CountingSort(a, b, k);

  for(i = 1 ; i <= n ; i++){
    if(i == n) printf("%d\n",b[i]);
    else printf("%d ",b[i]);
  }
  
  return 0;

}


void CountingSort(int *a, int *b, int k){

  int i,j;

  for(i = 0 ; i <= k ; i++) c[i] = 0;

  for(j = 1 ; j <= n ; j++) c[a[j]]++;

  for(i = 1; i <= k ; i++) c[i] = c[i] + c[i-1];

  for(j = n ; j >= 1 ; j--){
    b[c[a[j]]] = a[j];
    c[a[j]]--;
  }

}
