/****************
 *		*
 *ALDS_1_5_B	*
 *Merge Sort	*
 *		*
 *2019/08/20	* 
 *		*
 ****************/

#include<iostream>
#include<cstdio>

using namespace std;

#define MAX_ARRAY 500000
#define MAX_LIMIT 1000000001

int count_compare = 0;
int S[MAX_ARRAY] = {0};

void merge(int left,int mid,int right){
  int i,j,k;
  int n1 = mid - left;
  int n2 = right - mid;
  int Left[MAX_ARRAY];
  int Right[MAX_ARRAY];
  
  for(i=0;i<n1;i++) Left[i] = S[left + i];
  Left[n1] = MAX_LIMIT;
  for(j=0;j<n2;j++) Right[j] = S[mid + j];
  Right[n2] = MAX_LIMIT;

  i=0;
  j=0;

  for(k=left;k<right;k++){
    count_compare++;
    if(Left[i] <= Right[j]){
      S[k] = Left[i];
      i++;
    }
    else {
      S[k] = Right[j];
      j++;
    }
  }
}

void mergeSort(int left,int right){
  if((left + 1) < right){
    int mid = (left + right)/2;
    mergeSort(left,mid);
    mergeSort(mid,right);
    merge(left,mid,right);
  }

  return;
  
}

int main(void){

  int n=0;

  scanf("%d",&n);
  for(int i=0;i<n;i++) scanf("%d",&S[i]);

  mergeSort(0,n);

  for(int i=0;i<n;i++) {
    if(i > 0) printf(" ");
    printf("%d",S[i]);
  }
  printf("\n");

  printf("%d\n",count_compare);
  
  return 0;
}

