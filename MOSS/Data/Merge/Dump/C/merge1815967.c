#include<stdio.h>
#define M 1000000000
#define N 500001
void Merge(int Arr[],int left,int mid,int fuck);
void MergeSort(int Arr[], int left, int right);

int count = 0;

int main(){
  int Arr[N];
  int i;
  int n;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&Arr[i]);
  }
      MergeSort(Arr, 0, n);
      for(i = 0; i < n; i++){
    if(i == n-1)    printf("%d\n",Arr[i]);
    else printf("%d ",Arr[i]);
      }
      printf("%d\n",count);
      return 0;
}

void Merge(int Arr[],int left,int mid,int right){

  int i,k;
  int j = 0;
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1+1], R[n2+1];

  for (i = 0; i < n1; i++){
    L[i] = Arr[left + i];
  }
  for(i = 0; i < n2; i++){
    R[i] = Arr[mid + i];
  }
  L[n1]= M;
  R[n2]= M;
  i = 0;

  for(k = left; k < right; k++){
    count++;
    if (L[i] <= R[j]){
      Arr[k] = L[i];
    i = i + 1;
}
else {
      Arr[k] = R[j];
      j = j + 1;
      }
    }
  }

void MergeSort(int Arr[], int left, int right){
  int mid = 0;
  if(left + 1 < right){
    mid = (left + right)/2;
    MergeSort(Arr, left, mid);
    MergeSort(Arr, mid, right);
    Merge(Arr, left, mid, right);
  }
}
