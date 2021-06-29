#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct
{
  char a;
  int b;
  int c;
}card;
 
void quickSort(int,int);
int partition(int,int);
int inStable();
int n;
card A[1000000];
 
int main(){
 
  int i;
 
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf(" %c%d",&A[i].a,&A[i].b);
    A[i].c = i;
  }
  quickSort(1,n);
 
  if(inStable()==1){
printf("Stable\n");
  }
     else printf("Not stable\n");
   
  for(i = 1;i <= n;i++){
    printf("%c %d\n",A[i].a,A[i].b);
    
  }
  return 0;
}
 
void quickSort(p,r){
  int q;
 
  if(p < r){
    q = partition(p,r);
    quickSort(p,q-1);
    quickSort(q+1,r);
  }
}
 
int partition(int p,int r){
 
  int x;
  card y;
  int i,j;
 
  x=A[r].b;
  i=p-1;
 
  for(j=p;j<=r-1;j++){
    if(A[j].b<= x){
      i=i+1;
      y=A[i];
      A[i]=A[j];
      A[j]=y;
    }
  }
  y=A[i+1];
  A[i+1]=A[r];
  A[r]=y;
  return i+1;
}
 
int inStable()
{
  int i,j;
 
  for(i=1;i<=n;i++){
   
    if(A[i].b==A[i-1].b){
      if(A[i].c< A[i-1].c){
 return 0;
      }
    }
  }
  return 1;
}
