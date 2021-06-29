#include<stdio.h>
#define MAX 100001
 
typedef struct{
  char pattern;
  int num;
  int id;
} Card;
 
int Partition(Card*,int,int);
void QuickSort(Card*,int,int);
 
int main(void){
  int i,n,judge;
  Card A[MAX];
  char space;
 
  scanf("%d%d", &n, &space);
  for(i=0;i<n;i++){
    scanf("%c%d%c", &A[i].pattern, &A[i].num, &space);
    A[i].id=i;
  }
  //??¢???????¨
  //for(i=0;i<n;i++) printf("%c%d\n", A[i].pattern, A[i].num);
  //printf("\n");
 
  judge=0;
  QuickSort(A,0,n-1);
 
  for(i=0;i<n;i++){
    if(A[i].num == A[i+1].num && A[i].id > A[i+1].id && judge == 0){
      printf("Not stable\n");
      judge=1;
      break;
    }
  }
  if(judge==0) printf("Stable\n");
 
  for(i=0;i<n;i++) printf("%c %d\n", A[i].pattern, A[i].num);
 
  return 0;
}
 
int Partition(Card *A,int p, int r){
  int i,j,x;
  Card tmp;
 
  x=A[r].num;
 
  i=p-1;
  for(j=p;j<=r-1;j++){
    if(A[j].num<=x){
      i++;
      tmp=A[i];
      A[i]=A[j];
      A[j]=tmp;
    }
  }
 
  tmp=A[i+1];
  A[i+1]=A[r];
  A[r]=tmp;
 
  return i+1;
}
 
void QuickSort(Card *A,int p, int r){
  int q;
 
  if(p<r){
    q=Partition(A,p,r);
    QuickSort(A,p,q-1);
    QuickSort(A,q+1,r);
  }
 
  return;
}
