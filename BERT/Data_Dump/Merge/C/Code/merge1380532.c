#include <stdio.h>
#define N 500000
 
int tmp[N], count;
 
void MergeSort(int data[], int l, int r){
  int mid, i, j, k;

  if(l >= r) return;
  mid = (l + r) / 2;

  MergeSort(data, l, mid);
  MergeSort(data, mid+1, r);

  for(i=l;i<=mid;i++){
 tmp[i] = data[i];
}
  for(i=mid+1,j=r;i<=r;i++,j--){
 tmp[i] = data[j];
}

  i = l;
  j = r;

  for(k=l;k<=r;k++,count++){
    if(tmp[i] <= tmp[j]) data[k] = tmp[i++];
    else data[k] = tmp[j--];
  }
}
 
main(){
  int n, data[N], i;

  scanf("%d", &n);
  for(i=0;i<n;i++){
 scanf("%d", &data[i]);
}
  MergeSort(data, 0, n-1);

  for(i=0;i<n-1;i++){
 printf("%d ", data[i]);
}
  printf("%d\n%d\n", data[n-1], count);
  return 0;
}
