#include <stdio.h>

#define INFTY 1000000002

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int n,sum = 0;

int main(){
  int i,s[500000],left,right;

  scanf("%d",&n);
  if(n > 500000)return 0;

  for(i = 0;i < n;i++){
    scanf("%d",&s[i]);
  }
  left = 0;
  right = n;
  
  mergeSort(s,left,right);
  
 for(i = 0;i < n;i++){
   if(i > 0)printf(" ");
   printf("%d",s[i]);
 }
 printf("\n%d\n",sum);
      
  return 0;
}

void merge(int s[],int left,int mid,int right){
  int i = 0,j = 0,k,n1,n2,L[250001],R[250001];
 
  n1 = mid - left;
  n2 = right - mid;
  for(i = 0;i < n1;i++){
    L[i] = s[left + i];
  }
  for(i = 0;i < n2;i++){
    R[i] = s[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k = left;k < right ;k++){
    if(L[i] <= R[j]){
      s[k] = L[i];
      i += 1;
      sum++;
    }
    else{
      s[k] = R[j];
      j += 1;
      sum++;
    }
  }
}

void mergeSort(int s[],int left,int right){
  int mid;
 
  if(left + 1 < right){
    mid = (left + right)/2;
    mergeSort(s,left,mid);
    mergeSort(s,mid,right);
    merge(s,left,mid,right);
  }
  
}

