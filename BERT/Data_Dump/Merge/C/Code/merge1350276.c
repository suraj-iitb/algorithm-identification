#include<stdio.h>

#define INFTY 100000000000

int S[1000000];
int n;
int count=0;

void mergeSort(int,int);
void merge(int,int,int);

int main(){
  int i;

  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }

  mergeSort(0,n);

  for(i = 0;i < n-1;i++){
    printf("%d ",S[i]);
    //  printf("\n%d",i);
  }
  printf("%d\n",S[i]);

  printf("%d\n",count);
  return 0;
}

void mergeSort(int left,int right){
  int mid;

  if(left+1 < right){
    //  printf("ok\n");

    mid = (left+right)/2;
    // printf("1\n");
    mergeSort(left,mid);

    // printf("2\n");

    mergeSort(mid,right);
    merge(left,mid,right);
  }
}

void merge(int left,int mid,int right){

  int i, j, k;
  int n1,n2;
  int L[250001];
  int R[250001];

  n1 = mid - left;
  n2 = right - mid;

  for(i = 0;i <= n1-1;i++){
    // printf("%d\n",S[left + i]);
    L[i] = S[left + i];
  }
  for(i = 0;i <= n2-1;i++){
    R[i] = S[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;

  i = 0; 
  j = 0;

  for(k = left;k <= right-1;k++){
    count++;
    if(L[i] <= R[j]){
      // printf("ok\n");
     	S[k] = L[i]; 
	i = i + 1;
      }
    else{
      S[k] = R[j];
      j =j + 1;
    }
  }
}
