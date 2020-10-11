#include<stdio.h>

void merge(int *,int,int,int,int);
void Sort(int *,int,int,int);

int c,L[260000],R[260000];

int main(){
  int n,i;
  int S[500000];

  scanf("%d",&n);

  for(i = 0;i < n; i++) scanf("%d",&S[i]);
  Sort(S,n,0,n);
  for(i = 0; i < n; i++){
    if(i) printf(" ");
    printf("%d",S[i]);
  }
  printf("\n");
  printf("%d\n",c);
  
  return 0;
}

void merge(int S[],int n,int left,int mid,int right){
  int n1,n2,i,k,j,a,b;

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0; i < n1; i++) L[i] = S[left + i];
  for(i = 0; i < n2; i++) R[i] = S[mid + i];
  L[n1] = R[n2] = 1000000000;
  
  i = j = 0;
  for(k = left; k < right; k++){
    c++;
    if(L[i] <= R[j]){
      a = i++;
      S[k] = L[a];
    }
    else {
      b = j++;
      S[k] = R[b];
    }
  }
}

void Sort(int S[],int n,int left,int right){
  if(left+1 < right){
    int mid = (left + right)/2;
    Sort(S,n,left,mid);
    Sort(S,n,mid,right);
    merge(S,n,left,mid,right);
  }
}
    

