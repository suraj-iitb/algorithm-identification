#include<cstdio>
#include<cstdlib>

int n;
int cnt = 0;
int INFTY = RAND_MAX;

void merge(int S[],int left,int mid,int right){
  int n1,n2;
  
  n1 = mid - left;
  n2 = right - mid;
  
  int L[n1 + 1],R[n2 + 1];
  
  for(int i = 0;i < n1;i++){
    L[i] = S[left + i];
  }
  
  for(int i = 0;i < n2;i++){
    R[i] = S[mid + i];
  }
  
  L[n1] = INFTY;
  R[n2] = INFTY;
  
  int i = 0,j = 0;
  
  for(int k = left;k < right;k++){
    if(L[i] <= R[j]){
      S[k] = L[i];
      i += 1;
      cnt++;
    }else{
      S[k] = R[j];
      j += 1;
      cnt++;
    }
  }
}

void mergeSort(int S[],int left,int right){
  int mid;
  if(left + 1 < right){
    mid = (left + right) / 2;
    mergeSort(S,left,mid);
    mergeSort(S,mid,right);
    merge(S,left,mid,right);
  }
}
    
int main(){
  int S[500000];
  int left,right;
  
  std::scanf("%d",&n);
  
  for(int i = 0;i < n;i++){
    std::scanf("%d",&S[i]);
  }
  
  left = 0;
  right = n;
  
  mergeSort(S,left,right);
  
  for(int i = 0;i < n;i++){
    if(i > 0) std::printf(" ");
    std::printf("%d",S[i]);
  }
  
  std::printf("\n");
  std::printf("%d\n",cnt);
  
  return 0;
}

