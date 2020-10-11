#include<stdio.h>
#include<stdlib.h>

typedef struct{
  char mark;
  int num;
  int in_num;
}card;

void swap (card *A,int i,int j){
  card cmp;
  cmp=A[i];
  A[i]=A[j];
  A[j]=cmp;
}



int partition(card *A,int p,int r){
  card x = A[r];
  int j,i = p-1;

  for(j=p;j<r;j++){
    if(A[j].num <= x.num){
      i++;
      swap(A,i,j);
    }
  }
  swap(A,i+1,r);

  return i+1;
}

void quicksort(card *V,int p,int r){
  int q;
  if(p<r){
    q = partition(V,p,r);
    quicksort(V,p,q-1);
    quicksort(V,q+1,r);
  }
}


int check(card *A,int N){
  int i;
  
  for(i=1;i<N;++i){
    if(A[i].num == A[i+1].num && A[i].in_num > A[i+1].in_num) return 0;
  }
  return 1; 
}



int main(){
  int n,i;
  card *A,*B;

  scanf("%d",&n);

  A = malloc(sizeof(card)*(n + 1));
 

  for(i=1;i<n+1;++i){
    scanf(" %c %d",&A[i].mark,&A[i].num);
    A[i].in_num = i;
  }

  quicksort(A,1,n);
  
  if(check(A,n))printf("Stable\n");
  else printf("Not stable\n");

  for(i=1;i<=n;++i)printf("%c %d\n",A[i].mark,A[i].num);
 
  return 0;
}


