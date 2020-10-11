#include<stdio.h>
#include<limits.h>
typedef struct{
  int x;
  char c;
}card;
card B[100000];
 
int Partition(int p, int r){
  card t;
  int x,i,j;
  x = B[r].x;
  i = p-1;
  for( j = p; j< r;j++){
    if (B[j].x <= x){
      i = i+1;
      t=B[i];
      B[i]=B[j];
      B[j]=t;
    }
  }
    t = B[i+1];
    B[i+1] = B[r];
    B[r] = t;
  return i+1;
}
 
void Quicksort(int p,int r){
  int q;
  if( p < r){
     q = Partition( p, r);
     Quicksort( p, q-1);
     Quicksort( q+1, r);
      }
  }
 
void merge(int left,int mid,int right,card A[]){
  int i,j,k;
  int n1 = mid-left;
  int n2 = right-mid;
  card L[100000],R[100000];
 
  for(i = 0;i<n1;i++){
    L[i]=A[left+i];
  }
 
  for(i = 0;i<n2;i++){
    R[i]=A[mid+i];
  }
   
  L[n1].x=INT_MAX;
  R[n2].x=INT_MAX;
  i=0;
  j=0;
  for(k = left; k<right; k++){
    if(L[i].x<=R[j].x){
      A[k]=L[i++];
    }
    else {
      A[k]=R[j++];
     }
  
  }
   
}
void mergeSort(int left,int right,card A[]){
  if(left+1 < right ){
  int mid = (left+right)/2;
  mergeSort(left,mid,A);
  mergeSort(mid,right,A);
  merge(left,mid,right,A);
  }
}
 
int main(){
  int i,p,n;
  char c;
  card C[100000];
  scanf("%d%c",&n,&c);
 
  for(i=0;i<n;i++){
    scanf("%c%d%c",&C[i].c,&C[i].x,&c);
    B[i]=C[i];
  }
 
  p=0;
  mergeSort(0,n,C);
  Quicksort(0,n-1);
  for(i=0;i<n;i++){
    if(C[i].c!=B[i].c){
      printf("Not stable\n");
      break;
    }
    if(i==n-1)printf("Stable\n");
  }
 
  for(i=0;i<n;i++){
    printf("%c %d\n",B[i].c,B[i].x);
    }
 
  return 0;
}
