#include<stdio.h>
#define N 100001

typedef struct{
  char pattern;
  int num;
  int k;
}Card;
Card A[N];
void quicksort(int,int);
int partition(int,int);

int main(){
  int n,i,flag=0;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s %d",&A[i].pattern,&A[i].num);
    A[i].k=i;
  }
  quicksort(0,n-1);

  for(i=0;i<n-1;i++){
    if(A[i].num == A[i+1].num && A[i].k > A[i+1].k){
      flag=1;
      break;
    }
  }
  if(flag == 0){
    printf("Stable\n");
  }
  else{
    printf("Not stable\n");
  }
  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].pattern,A[i].num);
  }
  return 0;
}
void quicksort(int p,int r){
  int q;
  if(p<r){
    q=partition(p,r);
    quicksort(p,q-1);
    quicksort(q+1,r);
  }
}
int partition(int p,int r){
  int i,j,x;
  Card tmp;
  x=A[r].num;
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].num<=x){
      i=i+1;
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
