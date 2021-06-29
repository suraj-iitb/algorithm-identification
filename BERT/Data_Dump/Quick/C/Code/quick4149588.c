#include<stdio.h>
#include<stdlib.h>

typedef struct{
 char E;
 int n;
} card;

void isStable(card in[],card out[],int n){
  int i,j,a,f,p,flag=0;
  for(i=0;i<n;i++){
    f=0;
    for(j=0;j<n;j++){
      if(in[i].n==out[j].n){
        f=1;
        p=0;
        if(in[i].E!=out[j].E){
          for(a=i-1;a>=0;a--)
            if(in[a].E==out[j].E && in[a].n==out[j].n)p=1;
          if(p==0)
            flag=1;
        }
      }
      if(f==1)break;
    }
    if(flag==1) {
      printf("Not stable\n");
      return;    
    }
  }
  printf("Stable\n");
  return;
}
  
int partition(card *A,int p,int r){
  int i,j;
  card x,a;
  x=A[r];
  i=p-1;
  for(j=p;j<r;j++){
    if(A[j].n<=x.n){
      i++;
      a=A[i];
      A[i]=A[j];
      A[j]=a;
    }
  }
  a=A[i+1];
  A[i+1]=A[r];
  A[r]=a;
  return i+1;
}
void quicksort(card *A,int p,int r){
  int q;
  if(p<r){
    q=partition(A,p,r);
    quicksort(A,p,q-1);
    quicksort(A,q+1,r);
  }
}
int main(){
  int i;
  card in[100000];
  card out[100000];
  int N;
  int a;
  char b;
  char d;
  

  scanf("%d",&N);
	
  scanf("%c",&d);
  for(i=0;i<N;i++){
    scanf("%c",&b);
    scanf("%d",&a);
    scanf("%c",&d);
    in[i].n=a;
    out[i].n=a;
    in[i].E=b;
    out[i].E=b;
  }
  quicksort(out,0,N-1);
  isStable(in,out,N);
  for(i=0;i<N;i++){
      printf("%c %d\n",out[i].E,out[i].n);
  }
  return 0;
}

