#include <stdio.h>
#include <stdlib.h>

typedef struct node{
  int value;
  char symbol;
}DATA;

int partition(DATA *,int,int);
void quicksort(DATA *,int,int);
void merge(DATA *,int,int,int);
void mergeSort(DATA  *,int,int);

int n;
DATA leftDATA[100000/2+2],rightDATA[100000/2+2];

int main(){
  int i,tmp;
  DATA arr[100000],babble[100000];

  scanf("%d",&n);
  if(n>100000) exit(2);
  for(i=0;i<n;i++){
    scanf(" %c %d",&arr[i].symbol,&arr[i].value);
    babble[i].value=arr[i].value;
    babble[i].symbol=arr[i].symbol;
  }
  mergeSort(babble,0,n);
  quicksort(arr,0,n-1);
  for(i=0;i<n;i++){
    if(babble[i].value != arr[i].value || babble[i].symbol != arr[i].symbol){
      printf("Not stable\n");
      break;
    }
  }
  if(i==n) printf("Stable\n");
  for(i=0;i<n;i++){
    printf("%c %d\n",arr[i].symbol,arr[i].value);
  }
  return 0;
}

int partition(DATA arr[],int left,int right){
  int i,le;
  DATA tmp;
  le=left;
  for(i=left;i<right;i++){
    if(arr[i].value<=arr[right].value){
      tmp=arr[le];
      arr[le]=arr[i];
      arr[i]=tmp;
      le++;
    }
  }
  tmp=arr[le];
  arr[le]=arr[right];
  arr[right]=tmp;
  return le;
}

void quicksort(DATA arr[],int left,int right){
  int base;
  if(left<right){
    base = partition(arr,left,right);
    quicksort(arr,left,base-1);
    quicksort(arr,base+1,right);
  }
}

void mergeSort(DATA arr[],int le,int ri){
  int mid;
  if(le+1<ri){
    mid = (le+ri)/2;
    mergeSort(arr,le,mid);
    mergeSort(arr,mid,ri);
    merge(arr,le,mid,ri);
  }
}

void merge(DATA arr[],int le,int mid,int ri){
  int i,j,k;
  
  for(k=0;k<mid-le;k++){
    leftDATA[k]=arr[le+k];
  }
  for(k=0;k<ri-mid;k++){
    rightDATA[k]=arr[mid+k];
  }
  leftDATA[mid-le].value = rightDATA[ri-mid].value = 999999999;
  i=0;
  j=0;
  for(k=le;k<ri;k++){
    if(leftDATA[i].value<=rightDATA[j].value){
      arr[k] = leftDATA[i];
      i++;
    }else{
      arr[k] = rightDATA[j];
      j++;
    }
  }
  
}

