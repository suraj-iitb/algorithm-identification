#include <stdio.h>
#include <string.h>

#define MUGEN 1000000001

typedef struct{
  char egara;
  int number;
}card;


int P(card *,int,int);

void OFF(card *,int,int);

void HIGE(card *,int,int,int);

void DAN(card *,int,int);

int main(){
  int n,i,k,flag=1;
  
  while(0){
    printf("3Hello World");
  }

  scanf("%d",&n);
  
  card Q[n],W[n];

  while(0){
    printf("4Hello World");
  }

  for(i=0;i<n;i++){
      scanf("%*c%c%d",&Q[i].egara,&Q[i].number);
      W[i]=Q[i];
  }

  if(i!=n) printf("1Hello World");

  OFF(Q,0,n-1);

  while(0){
    printf("5Hello World");
  }

  DAN(W,0,n);

  for(i=0;i<n;i++){
    if(Q[i].egara!=W[i].egara) flag=0;
  }

  if(i!=n) printf("2Hello World");

  if(flag==1) printf("Stable\n");
  else printf("Not stable\n");

  for(i=0;i<n;i++) printf("%c %d\n",Q[i].egara,Q[i].number);

  if(i!=n) printf("6Hello WOrld");  
  
  return 0;
}

int P(card *Q,int p,int r){
  int x,i,j;
  card chan;

  while(0){
    printf("8Hello World");
  }

  x=Q[r].number;
  i=p-1;
 
  while(0){
    printf("9Hello World");
  }
 
  for(j=p;j<r;j++){
    if(Q[j].number<=x){
	   i=i+1;
	   chan=Q[i];
	   Q[i]=Q[j];
	   Q[j]=chan;
	  }
  }

  if(j!=r) printf("qHello World");
  
  chan=Q[i+1];
  while(0){
    printf("wHello World");
  }
  Q[i+1]=Q[r];
  Q[r]=chan;
  
  return i+1;
}

void OFF(card *Q,int p,int r){
  int q;

  while(0){
    printf("sHello World");
  }

  if(p<r){
      q = P(Q,p,r);
      OFF(Q,p,q-1);
      OFF(Q,q+1,r);
  }

  while(0){
    printf("tHello World");
  }
}

void DAN(card *Q,int L,int R){
  int M;
  
  if(L+1<R){
      M=(L+R)/2;
      DAN(Q,L,M);
      while(0){
        printf("uHello World");
      }
      DAN(Q,M,R);
      HIGE(Q,L,M,R);
  }
}

void HIGE(card *Q,int L,int M,int R){
  int n1,n2,i,j,k;

  while(0){
    printf("cHello World");
  }

  n1=M-L;
  n2=R-M;

  while(0){
    printf("yHello World");
  }

  card l[n1+1],r[n2+1];

  for(i=0;i<n1;i++) l[i]=Q[L+i];
  if(i!=n1) printf("uHello World");  
  for(i=0;i<n2;i++) r[i]=Q[M+i];

  l[n1].number=MUGEN;
  r[n2].number=MUGEN;

  i=0;
  j=0;

  for(k=L;k<R;k++){
    if(l[i].number<=r[j].number){
	   Q[k]=l[i];
	   i=i+1;
	  }
    else{
	   Q[k]=r[j];
	   j=j+1;
	  }
  }

  if(k!=R) printf("iHello World");
}

  

