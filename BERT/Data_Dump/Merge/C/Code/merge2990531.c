#include<stdio.h>

void mergeSort(int,int,int*);
void merge(int,int,int,int*);
int count=0;
int ans[500000];

int main(void){
  int data;
  int i;

  scanf("%d",&data);

  for(i = 0;i < data;i++){
    scanf("%d",&ans[i]);
  }
    mergeSort(0,data,ans);
  for(i = 0;i < data;i++){
if(i==data-1){printf("%d",ans[i]);
break;
}
      printf("%d ",ans[i]);
  }
  printf("\n%d\n",count);
  return 0;
}

void merge(int left,int mid,int right,int ans[]){
  int i;
  int j = 0;
  int k;

  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1];
  int R[n2];

  for(i = 0;i < n1;i++){
    L[i] = ans[left + i];
  }
  for(i = 0;i < n2;i++){
    R[i] = ans[mid + i];
  }
  L[n1] = R[n2] = 1000000000;
  i = 0;
  j = 0;
  for(k = left;k < right;k++){
    count++;
    if(L[i] <= R[j]){
      ans[k] = L[i];
      i = i + 1;
    }
    else{
      ans[k] = R[j];
      j = j + 1;
    }
  }
}

void mergeSort(int left,int right,int ans[]){
  if(left + 1 < right){
  int mid = (left + right) / 2;
  mergeSort(left,mid,ans);
  mergeSort(mid,right,ans);
  merge(left,mid,right,ans);
}
}

