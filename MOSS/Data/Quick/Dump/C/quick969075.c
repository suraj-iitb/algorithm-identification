#include<stdio.h>
#define N 100001

typedef struct{
  char mark;
  int num,id;
}Cards;

Cards A[N];


void QuickSort(int p, int r){
  int q;
  if (p<r){
    q = Partition(p,r);
    QuickSort(p,q-1);
    QuickSort(q+1,r);
  }
}

int Partition(int p, int r){
  int x,i,j;
  Cards temp;
  x = A[r].num;
  i = p-1;
  for (j=p;j<=r-1;j++){
    if (A[j].num<=x){
      i++;
      temp=A[i];
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
  int n,i,key,flag=0;
  char temp;
  scanf("%d%c",&n,&temp);
  for (i=0;i<n;i++){
    scanf("%c%d%c",&A[i].mark,&A[i].num,&temp);
    A[i].id=i;
  }
  QuickSort(0,n-1);
  for (i=1;i<n;i++){
    if ((A[i].num==A[i-1].num) && (A[i].id<=A[i-1].id)){
      printf("Not stable\n");
      flag=1;
      break;
    }
  }
  if (flag==0){
    printf("Stable\n");
  }

  for (i=0;i<n;i++){
    printf("%c %d\n",A[i].mark,A[i].num);
  }
 
  return 0;
}
