#include <stdio.h>
#define N 10000

int n, m, data[N], tmp[N];

void MergeSort(int data[], int left, int right){
  int mid, i, j, k;
  if(left >= right) return;
  mid = (left + right) / 2;
  MergeSort(data, left, mid);
  MergeSort(data, mid+1, right);
  for(i=left;i<=mid;i++) tmp[i] = data[i];
  for(i=mid+1, j=right;i<=right;i++, j--) tmp[i] = data[j];
  i = left;
  j = right;
  for(k=left;k<=right;k++){
    if(tmp[i] <= tmp[j]) data[k] = tmp[i++];
    else data[k] = tmp[j--];
  }
}

char find(int x){
  int l = 0, r = n;
  while(r - l >= 1){
    int i = (l + r) / 2;
    if(data[i] == x) return 1;
    else if(data[i] < x) l = i + 1;
    else r = i;
  }
  return 0;
}

main(){
  int i, in, ans = 0;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    scanf("%d", &data[i]);
  }
  MergeSort(data, 0, n-1);
  scanf("%d", &m);
  for(i=0;i<m;i++){
    scanf("%d", &in);
    if(find(in)) ans++;
  }
  printf("%d\n", ans);
  return 0;
}
