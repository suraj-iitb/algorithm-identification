#include<stdio.h>

void sort(int[],int,int);
void merge(int[],int,int,int);
int cnt = 0;

int main(){

  int S[1000000];
  int i,j;
  
  scanf("%d",&i);
 
   for(j = 0; j < i; j++){
        scanf("%ld",&S[j]);
   }

    sort(S,0,i);
  
  for(j = 0; j < i; j++){
   
    printf("%ld",S[j]);
    if(j < i-1){
      printf(" ");
    }
  }
  printf("\n%ld\n",cnt);
  
  return 0;
}


void sort(int A[],int left,int right){

  int mid;
  
  if(left + 1 < right){
    mid = (left + right)/2;
    sort(A,left,mid);
    sort(A,mid,right);
    merge(A,left,mid,right);
  }

}


void merge(int A[],int left,int mid,int right){
  int n1,n2,i,j,n;
  int L[mid - left];
  int R[right - mid];

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0; i < n1; i++){
    L[i] = A[left + i];
  }

  for(i = 0; i < n2; i++){
    R[i] = A[mid + i];
  }

  L[n1] = 999999999;
  R[n2] = 999999999;
  i = 0;
  j = 0;
  for(n = left; n < right; n++){
    if(L[i] < R[j]){
      A[n] = L[i];
      i++;
    }else{
      A[n] = R[j];
      j++;
    }
    cnt++;
  }

}


