#include<stdio.h>

#define MAX 500000

int count = 0;

void Merge(int a[],int left,int mid,int right);
void MergeSort(int a[],int left,int right);

int main(){
  int a[MAX],n,i;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&a[i]);
  }

  MergeSort(a,0,n);

  for(i = 0; i < n; i++){

    if(i == n-1){
      printf("%d\n",a[i]);
      printf("%d\n",count);
      break;
    }
    printf("%d ",a[i]);
  }

  return 0;
}



void Merge(int a[],int left,int mid,int right){

  int n1 = mid-left, n2 = right-mid, l[n1],r[n2],i,j,k;


  for(i = 0; i < n1; i++){
    l[i] = a[left+i];
  }

  for(i = 0; i < n2; i++){
    r[i] = a[mid+i];
  }

  l[n1] = 1000000000;
  r[n2] = 1000000000;

  i = 0;
  j = 0;

  for(k = left; k < right ;k++){
    if(l[i] <= r[j]){
      a[k] = l[i];
      i++;
      count++;
    }

    else{
      a[k] = r[j];
      j++;
      count++;
    }

  }
}



void MergeSort(int a[],int left,int right){

  int mid;

  
  if(left+1 < right){
    mid = (left+right)/2;
    MergeSort(a,left,mid);
    MergeSort(a,mid,right);
    Merge(a,left,mid,right);
  }

}

