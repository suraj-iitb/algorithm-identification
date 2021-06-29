#include <stdio.h>
#define N 500000

int tmp[N], cnt;

void MergeSort(int data[], int left, int right){
  int mid, i, j, k;
  if(left >= right) return;
  mid = (left + right) / 2;
  MergeSort(data, left, mid);
  MergeSort(data, mid+1, right);
  for(i=left;i<=mid;i++) tmp[i] = data[i];
  for(i=mid+1,j=right;i<=right;i++,j--) tmp[i] = data[j];
  i = left;
  j = right;
  for(k=left;k<=right;k++,cnt++){
    if(tmp[i] <= tmp[j]) data[k] = tmp[i++];
    else data[k] = tmp[j--];
  }
}

main(){
  int n, data[N], i;
  scanf("%d", &n);
  for(i=0;i<n;i++) scanf("%d", &data[i]);
  MergeSort(data, 0, n-1);
  for(i=0;i<n-1;i++) printf("%d ", data[i]);
  printf("%d\n%d\n", data[n-1], cnt);
  return 0;
}
