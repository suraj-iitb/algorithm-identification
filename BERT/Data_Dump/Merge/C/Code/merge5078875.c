#include<stdio.h>
#include<limits.h>

int L[500000],R[500000],A[500000],c=0;

void merge(int left,int mid,int right){
  int n1,n2,i,j,k;

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0;i < n1;i++){
    L[i] = A[left + i];
    
  }
 
  for(i = 0;i < n2;i++){
    R[i] = A[mid + i];
   
  }
  
 
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  
  
  i = 0;
  j = 0;
  for(k = left;k < right;k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
          
      c++;
    }else{
      A[k] = R[j];
      j = j + 1;
      c++;
    }
  }
}

void mergesort(int left,int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right) / 2;
    mergesort(left, mid);
    mergesort(mid, right);
    merge(left,mid,right);
  }
 
}

int main()
{
  int i,s,t;

  scanf("%d",&s);

  for(i = 0;i < s;i++){
    scanf("%d",&A[i]);
  }

  mergesort(0,s);

  for(i = 0;i < s;i++){
    printf("%d",A[i]);
    if(i != s-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",c);  
  return 0;
}


 

