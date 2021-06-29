#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int number;
  int check;
  char str[2];
}Card;

Card A[100000];

int partition(int p,int r){
  int i,j,x;
  Card hozon;
  x=A[r].number;
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].number<=x){
      i++;
      hozon=A[i];
      A[i]=A[j];
      A[j]=hozon;
    }
  }
  hozon=A[i+1];
  A[i+1]=A[r];
  A[r]=hozon;
  return i+1;
}

void quicksort(int p,int r){
  int q;
  if(p<r){
    q=partition(p,r);
    quicksort(p,q-1);
    quicksort(q+1,r);
  }
}
int main(){
  int i,n,cnt;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%s%d",A[i].str,&A[i].number);
    A[i].check=i;
  }
  quicksort(0,n-1);
  cnt=0;
  for(i=0;i<n-1;i++){
    if(A[i].number==A[i+1].number && A[i].check>A[i+1].check)cnt++;
  }
  if(cnt>0)printf("Not stable\n");
  else printf("Stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].str[0],A[i].number);
  }
  return 0;
}

