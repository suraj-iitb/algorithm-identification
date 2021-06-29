#include<stdio.h> 
#define MAX 100001

typedef struct Card{
  char mark;
  int num;
  int index;
}c;

int n;

int Partition(c A[],int p,int r){
  c t,u;
  int i,j,s;
  s=A[r].num;
  i=p-1;
  for(j=p;j<=r-1;j++){
    if(A[j].num<=s){
      i++;
      t=A[i];        /*Exchange A[i] and A[j]*/
      A[i]=A[j];
      A[j]=t;
    }
  }
  u=A[i+1];          /*Exchange A[i+1] and A[r]*/
  A[i+1]=A[r];
  A[r]=u;
  return i+1;
}

void QuickSort(c Q[],int p,int r){
  int q;
  if(p<r){
    q=Partition(Q,p,r);
    QuickSort(Q,p,q-1);
    QuickSort(Q,q+1,r);
  }
}

int JudgeStability(c K[],int n){
  int i;
  for(i=1;i<n;i++){
    if((K[i-1].num==K[i].num) && (K[i-1].index>K[i].index)){
      return 0; /*Not Stable*/
    } 
  }
  return 1;
}

int main(){
  int i;
  c P[MAX];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf(" %c %d",&P[i].mark,&P[i].num);
    P[i].index = i;
  }

  QuickSort(P,0,n-1);
  if(JudgeStability(P,n)==1) printf("Stable\n");
  else if(JudgeStability(P,n)==0) printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",P[i].mark,P[i].num);
  }
  return 0;
}
