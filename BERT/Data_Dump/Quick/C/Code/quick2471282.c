#include <stdio.h>
#include <stdlib.h>
 
void quicksort(int,int);
void partitition(int,int);
typedef struct{
 
  int num;
  char m[2];
  int check;
   
} data;
 
data A[100000];
 
int main(){
 
  int n,i,r,a,c=0;
  scanf("%d",&n);
 
  for(i=0;i<n;i++){
    scanf("%s %d",A[i].m,&A[i].num);
    A[i].check=i;
  }
   quicksort(0,n-1);
 
   for(i=0;i<n-1;i++){
     if(A[i].num==A[i+1].num && A[i].check>A[i+1].check) c++;
   }
 
   if(c>0) printf("Not stable\n");
   else printf("Stable\n");
    
  for(i=0;i<n;i++){
    printf("%c %d\n",A[i].m[0],A[i].num);
 
    }
  return 0; 
}
 
int partition(int p,int r){
  int x,j,i;
  data a,b;
  x=A[r].num;
  i=p-1;
  for(j=p;j<r;j++){
   
    if(A[j].num<=x){
      i=i+1;
      a=A[i];
      A[i]=A[j];
      A[j]=a;
    }
  }
  b=A[i+1];
  A[i+1]=A[r];
  A[r]=b;
   
  return i+1;
}
 
void quicksort(p,r){
  int q;
  if(p<r){
    q=partition(p,r);
    quicksort(p,q-1);
    quicksort(q+1,r);
  }
 
}
