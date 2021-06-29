#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int num;
  int mmm;
  char mark;
}Card;


int n,x;

int pertition(Card *A,int p,int r){
  int i,j;
  Card tmp;
  x=A[r].num;
  i=p-1;
  for(j=p;j<r;j++){
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

void quickSort(Card *A,int p,int r){
  int q;
  if(p<r){
    q = pertition(A,p,r);
    quickSort(A,p,q-1);
    quickSort(A,q+1,r);
  }
}

int main(void){
  int i,q,flag=0;
  Card *A;
  char spe;
  scanf("%d%c",&n,&spe);
  A=malloc(n*sizeof(Card));
  for(i=0;i<n;i++){
    scanf("%c%d%c",&A[i].mark,&A[i].num,&spe);
    A[i].mmm=i;
  }
  quickSort(A,0,n-1);
  for(i=0;i<n-1;i++){
    if(A[i].num==A[i+1].num && A[i].mmm>A[i+1].mmm){
      flag++;
      break;
    }
  }
  if(flag==0) printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].mark,A[i].num);
  }
  free(A);
  return 0;
}
