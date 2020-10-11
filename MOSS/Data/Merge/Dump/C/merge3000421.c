#include <stdio.h>

#define MAX 500000
#define INFTY 2000000000

void marge(int *,int,int,int);
void margeSort(int *,int,int);

int L[MAX];
int R[MAX];
int sort_count=0;

int main(){
  int i=0;
  int j=0;
  int n=0;
  int S[MAX];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  margeSort(S,0,i);

  for(i=0;i<n;i++){
    if(i!=0)printf(" ");
    printf("%d",S[i]);
  }
  printf("\n");
  printf("%d\n",sort_count);
  
  return 0;
}

void marge(int *S,int left,int mid, int right){
  int i=0;
  int j=0;
  int n_S=0;
  int n_left=0;
  int n_right=0;
  
  n_left=mid-left;
  n_right=right-mid;
  
  for(i=0;i<n_left;i++){
    L[i]=S[left+i];
  }
  
  for(i=0;i<n_right;i++){
    R[i]=S[mid+i];
  }
  
  L[n_left]=INFTY;
  R[n_right]=INFTY;
  i=0;
  j=0;
  
  for(n_S=left;n_S<right;n_S++){
    sort_count++;
    if(L[i]<=R[j]){
      S[n_S]=L[i];
      i++;
    }
    else{
      S[n_S]=R[j];
      j++;
    }
    
  }

}

void margeSort(int *S,int left,int right){
  int mid=0;
  if(left+1<right){
    mid=(left+right)/2;
    margeSort(S,left,mid);
    margeSort(S,mid,right);
    marge(S,left,mid,right);
  }
}

