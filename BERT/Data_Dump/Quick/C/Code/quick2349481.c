#include<stdio.h>
#define MAX 100000

typedef struct{
  char card;
  int value;
  int key;
}Roll;

int partition(Roll *A,int p,int r){
  int x = A[r].value;
  int i=p-1,j;
  Roll tmp;
  for(j=p;j<r;j++){
    
    if(A[j].value<=x){
      i+=1;
      tmp=A[i];
      A[i]=A[j];
      A[j]=tmp;
    }
  }
      tmp = A[i+1];
      A[i+1]=A[r];
      A[r]=tmp;
  

    return i+1;
}
void quickSort(Roll *A,int p,int r){
  int q;
  if(p < r){
    q = partition(A,p,r);
    quickSort(A,p,q-1);
    quickSort(A,q+1,r);
  }
}

int main(){

  Roll A[MAX];
  int i,j,n,flag=0;

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    scanf(" %c%d",&A[i].card,&A[i].value);
    A[i].key = i;
  }

  quickSort(A,0,n-1);

  for(i=0;i<n;i++){
    if(A[i].value==A[i+1].value&&A[i].key>A[i+1].key){
      flag=5;
      break;
    }
  }
    if(flag==5)printf("Not stable\n");
    else printf("Stable\n");
  
  for(i=0;i<n;i++) printf("%c %d\n",A[i].card,A[i].value);

  return 0;
}
