//2019.12.22
//s1270188 xxxmk2
//alds1_06c

#include<stdio.h>

#define N 100000

//prototype
int partition(int,int);
void quicksort(int,int);
void swap(int,int);
int judge(void);

//global
char Aa[N], Bb[N];
int A[N], B[N], num;

int main(){
  int i;

  //input
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf(" %c %d",&Aa[i],&A[i]);
    Bb[i]=Aa[i];
    B[i]=A[i];
  }
  
  //quicksort
  quicksort(0,num-1);

  //judge
  if(judge()==0) printf("Stable\n");
  else printf("Not stable\n");
  
  //output
  for(i=0;i<num;i++) printf("%c %d\n",Aa[i],A[i]);
    
  return 0;
}

int partition(int p,int r){
  int x, i, j, sub;

  x=A[r];
  i=p-1;

  for(j=p;j<r;j++){
    if(A[j]<=x){
      i++;
 
      swap(i,j);
    }
  }

  swap(i+1,r);

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

void swap(int a, int b){
  int manami;
  char momo;

  momo=Aa[a];
  Aa[a]=Aa[b];
  Aa[b]=momo;

  manami=A[a];
  A[a]=A[b];
  A[b]=manami;
}

int judge(void){
  int i, j;

  for(i=0;i<num;i++){
    for(j=0;j<num;j++){

      if(A[i]==B[j]){
	B[j]=-1;
	if(Aa[i]!=Bb[j]) return 1;
	else break;
      }
    }
  }
  
  return 0;
}


