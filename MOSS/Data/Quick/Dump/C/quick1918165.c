#include <stdio.h>

#define N 100000
typedef struct {
  char mark;
  int num;
  int s;
}Card;

void quickSort(Card *A,int p,int r){
  int q;
  
  if(p<r){
    q = partition(A,p,r);
    quickSort(A,p,q-1);
    quickSort(A,q+1,r);
  }
}

int partition(Card *A,int p,int r){

  int i,j,x;
  Card temp;
  
  x=A[r].num;
  i=p-1;

  for(j=p; j<r; j++){
    if (A[j].num <= x){
    i=i+1;
    temp = A[i];
    A[i]=A[j];
    A[j]=temp;
    }
  }
  temp=A[i+1];
  A[i+1]=A[r];
  A[r]=temp;

  return i+1;
}

int main(){

  int i,j,n,p=0,r,flag=0;
  char c;
  Card A[N];

  scanf("%d%c",&n,&c);

  for(i=0; i<n; i++){
    scanf("%c%d%c",&A[i].mark,&A[i].num,&c);
    A[i].s=i;
  }

  r=n-1;
  
  quickSort(A,p,r);

  for(i=0;i<r-1;i++){
    if(A[i].num == A[i + 1].num && A[i].s > A[i + 1].s){
      printf("Not stable\n");
      flag = 1;
      break;
    }
  }

  if(flag==0) printf("Stable\n");

  
  for(i=0; i<n; i++){
    printf("%c %d\n",A[i].mark,A[i].num);
  }
  
  return 0;
}
