#include<stdio.h>

#define Max 100000

typedef struct{
  char c;
  int a;
  int b;
} Card;

Card A[100001];


int partition(int,int);
void quicksort(int, int);


int main(){

  int i,n,q,flag = 0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c %d",&A[i].c,&A[i].a);
    A[i].b=i;
  }

  quicksort(0,n-1);
  
  for(i=0;i<n-1;i++){
    if(A[i].a==A[i+1].a){
      if(A[i].b>A[i+1].b)flag = 1;
    }
  }
  
  if(flag == 1)printf("Not stable\n");
  else printf("Stable\n");
  
  for(i=0;i<n-1;i++){
    printf("%c %d\n",A[i].c,A[i].a);
  }
  printf("%c %d\n",A[i].c,A[i].a);

  return 0;
  
}


int partition(int p,int r){
  int x;
  int i,j;
  int s,u;
  char y,t;
  
  x=A[r].a;
  i=p-1;
  for(j=p; j < r; j++){
    if(A[j].a<= x){
      i++;
      s=A[i].a;
      t=A[i].c;
      u=A[i].b;
      A[i].a=A[j].a;
      A[i].c=A[j].c;
      A[i].b=A[j].b;
      A[j].a=s;
      A[j].c=t;
      A[j].b=u;
    }
  }
  s=A[i+1].a;
  t=A[i+1].c;
  u=A[i+1].b;
  A[i+1].a=A[r].a;
  A[i+1].c=A[r].c;
  A[i+1].b=A[r].b;
  A[r].a=s;
  A[r].c=t;
  A[r].b=u;
  
  return i+1;
}

void quicksort(int p, int r){
  int q;
  if(p<r){
    q = partition(p,r);
    quicksort(p,q-1);
    quicksort(q+1,r);
  }
}
