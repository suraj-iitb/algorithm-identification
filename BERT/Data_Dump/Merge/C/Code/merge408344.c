/*s1190073  Rina Sato
  File name: prog5b.c
  This is a Merge Sort program.*/

#include <stdio.h>
#define SENTINEL 1000000003

int Merge(int S[],int left,int mid,int right){
  int n1,n2,i,j,k,count=0; 
  int L[500000],R[500000];

  n1 = mid - left;
  n2 = right - mid;
  
  for(i = 0 ; i < n1 ; i++){
    L[i] = S[left+i];
  }
  for(j = 0 ; j < n2 ; j++){
    R[j] = S[mid+j];
  }
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  
  i = 0;
  j = 0;
  
  for(k = left ; k < right ; k++){
    if(L[i] <= R[j]){	
      S[k] = L[i];
      i++;
    }
    else {
      S[k] = R[j];
      j++;
    }
    count++;
  }
  return count;
}

int MergeSort(int S[],int left,int right){
  int mid=0,count=0;
  int count1=0,count2=0,count3=0;
  if(left+1 < right){
    mid = (left+right)/2;
    
    count1 = MergeSort(S,left,mid);
    count2 = MergeSort(S,mid,right);
    count3 = Merge(S,left,mid,right);
  }
  count = count1+count2+count3;
  return count;
}
int main(void){
  int n,S[500000],i,count=0;
  int left,right,mid;
  
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&S[i]);
  }
 
  count = MergeSort(S,0,n);

  for(i = 0 ; i < n ; i++){
    printf("%d",S[i]);
    if(i <= n-2){
      printf(" ");
    }
  }
  
  printf("\n%d\n",count);
  return 0;
}
