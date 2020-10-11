#include <stdio.h>
 
int A[100000],od[100000];
char C[100000];
 
int Partition(int A[],char C[],int od[],int p,int r){
  int tp1,tp2,tpM,tpm,tpC,tpc;
  int i,j,x,stability,n;
   
  x = A[r];
  i = p-1;
  for(j = p ; j < r ; j++){
    if(A[j] <= x){
      i = i+1; 
      tp1 = A[i];
      tpM = C[i];
      tpC = od[i];
       
      A[i] = A[j];
      C[i] = C[j];
      od[i] = od[j];
      
      A[j] = tp1;
      C[j] = tpM;
      od[j] = tpC;
    }
  }
  tp2 = A[i+1];
  tpm = C[i+1];
  tpc = od[i+1];
   
  A[i+1] = A[r];
  C[i+1] = C[r];
  od[i+1] = od[r];
   
  A[r] = tp2;
  C[r] = tpm;
  od[r] = tpc;
   
  return i+1;
}
 
void Quicksort(int A[],char C[],int od[],int p,int r){
  int q;
   
  if(p < r){
    q = Partition(A,C,od,p,r);
    Quicksort(A,C,od,p,q-1);
    Quicksort(A,C,od,q+1,r);
  }
}
 
int main(){
  int n,i,stability=0;
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf(" %c%d",&C[i],&A[i]);
  }  
  for(i = 0 ; i < n ; i++){
    od[i] = i;
  }
  Quicksort(A,C,od,0,n-1);
  for(i = 0 ; i < n-1 ; i++){
    if(A[i] == A[i+1]){
      if(od[i] > od[i+1]){
        stability = 1;
        break;
      }
    }  
  }
  if(stability == 1){
    printf("Not stable\n");
  }
  else printf("Stable\n");
   
  for(i = 0 ; i < n ; i++){
    printf("%c %d\n",C[i],A[i]);
  }
   
  return 0;
}
