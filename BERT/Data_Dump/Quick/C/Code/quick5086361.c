#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#define MAX 100001

typedef struct{
  char type;
  int num;
  int r;
}CARD;

CARD A[MAX],B[MAX];

int partition(CARD *,int,int);
void quicksort(CARD *,int,int);

int main(){
  int n,i,j,l = 0;
  int max = 0;
  CARD tmp;

  scanf("%d",&n);

  for(i = 1; i <= n ; i++){
    scanf(" %c",&A[i].type);
    scanf("%d",&A[i].num);
    A[i].r = i;
    if(max < A[i].num)max = A[i].num;
  }

  for(i = 1; i <= n ; i++){
    B[i] = A[i];
  }

  quicksort(B,0,n);

  for(i = 1; i <= n ;i++){
    if(B[i-1].num == B[i].num && B[i-1].r > B[i].r)l++;
  }
	

  if(l != 0){
    printf("Not stable\n");
  }else{
    printf("Stable\n");
  }
  
  for(i = 1; i <= n ; i++){
    printf("%c %d\n",B[i].type,B[i].num);
  } 

  return 0;
}
    

int partition(CARD *A,int p,int r){
  int x,i,j;
  CARD tmp;

  x = A[r].num;
   i = p-1;

  for(j = p; j < r;j++){
    if(A[j].num <= x){
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

 void quicksort(CARD *A,int p,int r){
   int q;
   if(p < r){
     q = partition(A,p,r);
     quicksort(A,p,q-1);
     quicksort(A,q+1,r);
   }
 }


