#include<stdio.h>
  
typedef struct{
  char m[2];
  int n;
  int o;
} Card;
  
int partition(Card *A, int p, int r){
  int i, j, a;
  Card tmp;
  a = A[r].n;
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].n<=a){
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
 
void quickSort(Card *A, int p, int r){
  int q; 
  if(p<r){
    q=partition(A,p,r);
    quickSort(A,p,q-1);
    quickSort(A,q+1,r);
  }
}

int main(){
  Card A[100000];
  int i,j,nn,v=0;
  
  scanf("%d",&nn);
  for(i=0;i<nn;i++){
    scanf("%s %d",A[i].m, &A[i].n);
    A[i].o = i + 1;
  }
  quickSort(A, 0, nn-1);
  for(i=0;i<nn;i++){
    if(A[i].o>A[i+1].o&&A[i].n==A[i+1].n){
      v++;
      break;
    }
  }
  
  if(v==0) printf("Stable\n");
  else printf("Not stable\n");
  for(i=0;i<nn;i++) printf("%s %d\n",A[i].m, A[i].n);
  return 0;
  
}
