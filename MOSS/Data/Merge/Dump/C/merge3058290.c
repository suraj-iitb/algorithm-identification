#include<stdio.h>
#include<limits.h>

#define MAX_DATA 500000

int S[MAX_DATA];
int counter = 0;

int merge(int left , int mid , int right){
  int i , j , k ;

  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1 + 1];
  int R[n2 + 1];
  for(i = 0 ; i < n1 ; i++){
    L[i] = S[left + i];
  }
  for(i = 0 ; i < n2 ; i++){
    R[i] = S[mid + i];
  }
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;
  i = 0;
  j = 0;
  for(k = left ; k < right ; k++){
    if(L[i] <= R[j]){
      S[k] = L[i];
      i = i + 1;
      counter++;
    }
    else{
      S[k] = R[j];
      j = j + 1;
      counter++;
    }
  }
}

int mergeSort(int left ,int right){
  if(left+1 < right){
    int mid = (left+right)/2;
    mergeSort(left,mid);
    mergeSort(mid , right);
    merge(left, mid , right);
  }

}


int main(){

  int i;
  int n;
  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&S[i]);
  }
  mergeSort(0 , n);

  for(i = 0 ; i < n ; i ++){
    if(i > 0)printf(" ");
    printf("%d",S[i]);
  }
  printf("\n");
  printf("%d\n",counter);

}

