#include<stdio.h>
#include<stdlib.h>
#define N 500000

void merge(int,int,int);
void mergesort(int,int);

int n;
int S[N];
int count=0;

int main(){

  int i;
  /*input*/
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  /*merge sort*/
  mergesort(0,n);

   /*output*/
  for(i=0;i<n-1;i++){
    printf("%d ",S[i]);
  }
  printf("%d\n",S[n-1]);

  printf("%d\n",count);
  
  return 0;
}

void merge(int left,int right,int middle){
    
      int i,j,k;
  int L1 = middle - left;
  int L2 = right - middle;
  int l[L1];
  int r[L2];

  for(i=0;i<L1;i++){
    l[i]=S[left+i];
  }

  for(i=0;i<L2;i++){
    r[i]=S[middle+i];
  }

  i=0;
  j=0;
  k=left;
  while(i<L1 && j<L2){
    if(l[i]<=r[j]){
      S[k]=l[i];
      i++;
      count++;
    }
    else{
      S[k]=r[j];
      j++;
      count++;
    }
    k++;
  }
  
     while(i<L1){
      S[k]=l[i];
      i++;
      count++;
      k++;
    }

    while(j<L2){
      S[k]=r[j];
      j++;
      count++;
      k++;
    }
}

void mergesort(int left,int right){

  int middle;

  if(left+1 < right){
    middle=left+(right-left)/2;
    mergesort(left,middle);
    mergesort(middle,right);
    merge(left,right,middle);
  }
}
