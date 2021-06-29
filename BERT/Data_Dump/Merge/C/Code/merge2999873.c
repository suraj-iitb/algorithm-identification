#include<stdio.h>
#define INFTY 2000000000;
int cnt = 0;

int merge(int S[],int left,int mid,int right){
  int n1,n2;
  int i,j,k;
  n1 = mid - left;
  n2 = right - mid;
  int L[n1+1],R[n2+1];
  for(i = 0;i<=n1-1;i++){
    L[i] = S[left + i];
    
  }
  for(i = 0;i<=n2 - 1;i++){
    R[i] = S[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for(k = left;k<=right-1;k++){
    if(L[i] <= R[j]){
      S[k] = L[i];
      i = i+1;
      cnt++;
    }
    else{
      S[k] = R[j];
      j = j+1;
      cnt++;
    }
  }
  
  return *S;
}
void mergeSort(int S[],int left,int right){
  int mid;
  if((left+1) < right){
    mid = (left+right)/2;
    mergeSort(S,left,mid);
    mergeSort(S,mid,right);
    merge(S,left,mid,right);
   
  }
}

int main(){
  int n,s[500000];
  int i;

  scanf("%d",&n);
  for(i = 0;i<n;i++){
    scanf("%d",&s[i]);
  }

 
    mergeSort(s,0,n);
   for(i = 0;i<n;i++){
     if(i>0)printf(" ");
    printf("%d",s[i]);
      
  }
  printf("\n%d\n",cnt);
  
  

  return 0;
}

