#include<stdio.h>
 
#define MAX 100000
 
int count[MAX+1];
 
void quicksort(int *,char *,int,int);
int partition(int *,char *,int,int);
int stable(int *,int);
 
int main() {
 
  int i,n,k;
  char B[MAX+1],c,d,e;
  int A[MAX+1];
   
 
  scanf("%d%c",&n,&e);
   
  for(i=1;i<n+1;i++){
   scanf("%c%c%d%c",&B[i],&c,&A[i],&d);
   count[i]=i;
  }
 
  quicksort(A,B,1,n);
 
  if(stable(A,n)==0) printf("Stable\n");
  else printf("Not stable\n");
 
  for(k=1;k<=n;k++){
    printf("%c %d\n",B[k],A[k]);
  }
 
  return 0;
}
 
void quicksort(int *A,char *B,int p,int r){
  int q;
   
  if(p<r){
    q=partition(A,B,p,r);
    quicksort(A,B,p,q-1);
    quicksort(A,B,q+1,r);
  }
}
 
int partition(int *A,char *B,int p,int r){
  int x,i,j,s,swap;
  char exc;
 
   x=A[r];
   i=p-1;
 
  for(j=p;j<r;j++){
    if(A[j]<=x){
      i++;
      swap=A[i];
      A[i]=A[j];
      A[j]=swap;
      exc=B[i];
      B[i]=B[j];
      B[j]=exc;
      s=count[i];
      count[i]=count[j];    
      count[j]=s;
    }
}
      swap=A[i+1];
      A[i+1]=A[r];
      A[r]=swap;
      exc=B[i+1];
      B[i+1]=B[r];
      B[r]=exc;
      s=count[i+1];
      count[i+1]=count[r];    
      count[r]=s;
 
      return i+1;
}
 
int stable(int *A,int n){
  int i;
 
  for(i=1;i<=n;i++){
    if(A[i]==A[i+1]){
      if(count[i]>count[i+1]) return 1;
    }
  }
  return 0;
 
}
