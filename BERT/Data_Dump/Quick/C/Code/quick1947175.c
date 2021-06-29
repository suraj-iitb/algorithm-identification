#include<stdio.h>

typedef struct{
  int x;
  char c;
  int num;
}card;

card A[100001];

int Partition(card* ,int,int);
void Quicksort(card* ,int,int);

int main(){
  int i,k,n,f=0;
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
 
    scanf(" %c %d",&A[i].c,&A[i].x);
    A[i].num=i;
}
  Quicksort(A,0,n-1);
  for(i=1;i<n;i++){
    if(A[i].x==A[i-1].x){
      if(A[i].num<A[i-1].num)f=-1;
    }
 
  }
  if(f==0)printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].c,A[i].x);
  }
  return 0;
}

int Partition(card* A,int p,int r){
  card k=A[r],tmp;
  int i=p-1,j;
  
  for(j=p;j<r;j++){
    if(A[j].x <= k.x){
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
 
void Quicksort(card* A,int p,int r){  
  int q;

  if(p<r){
  q=Partition(A,p,r);
  Quicksort(A,p,q-1);
  Quicksort(A,q+1,r);
 }
}
 
