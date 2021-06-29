/****************
 *		*
 * ALDS_1_6_C	*
 * QuickSort	*
 *		*
 * 2019/08/26	*
 *		*
 ****************/

#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

#define	MAX_ARRAY	100000
#define MAX_LIMIT 	1000000001


typedef struct{
  char type;
  int value;
}Card;

Card A[MAX_ARRAY];
Card B[MAX_ARRAY];

void merge(int left,int mid,int right){
  int i,j,k;
  int n1 = mid - left;
  int n2 = right - mid;
  Card Left[MAX_ARRAY/2+1];
  Card Right[MAX_ARRAY/2+1];
  
  for(i=0;i<n1;i++) Left[i] = B[left + i];
  Left[n1].value = MAX_LIMIT;
  for(j=0;j<n2;j++) Right[j] = B[mid + j];
  Right[n2].value = MAX_LIMIT;

  i=0;
  j=0;

  for(k=left;k<right;k++){
    if(Left[i].value <= Right[j].value){
      B[k] = Left[i];
      i++;
    }
    else {
      B[k] = Right[j];
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


void swap(int i,int j){
  Card temp = A[i];
  A[i] = A[j];
  A[j] = temp;

  return;
}

int partition(int p,int r){
  Card x = A[r];
  int i = p-1;

  for(int j=p;j<r;j++){
    if(A[j].value <= x.value){
      i++;
      swap(i,j);
    }
  }
  swap(i+1,r);

  return i+1;
  
}

void quickSort(int p,int r){
  if(p < r){
    int q = partition(p,r);
    quickSort(p,q-1);
    quickSort(q+1,r);
  }
}

int main(void){
  int n=0;
  char input_sentence[10];
  int input_value = 0;
  bool stable=true;
  
  scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%s %d",input_sentence,&input_value);
    A[i].type = input_sentence[0];
    B[i].type = input_sentence[0];
    A[i].value = input_value;
    B[i].value = input_value;
  }
  
  quickSort(0,n-1);
  mergeSort(0,n);

  for(int i=0;i<n && stable == true;i++){
    if(A[i].type != B[i].type) stable = false;
  }


  if(stable)
    printf("Stable\n");
  else
    printf("Not stable\n");
  
  for(int i=0;i<n;i++){
    printf("%c %d\n",
	   A[i].type,A[i].value);
  }
  
  return 0;
}

