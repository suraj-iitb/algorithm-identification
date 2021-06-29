#include<stdio.h>

int binarySearch(int);

int n, Sn[100000];

int main(void){
  int q, Tq;
  int i, cnt=0;

  scanf("%d", &n);

  for(i=0;i<n;i++)  scanf("%d", &Sn[i]);

  scanf("%d", &q);

  for(i=0;i<q;i++){
    scanf("%d", &Tq);
    if(binarySearch(Tq)) cnt++;
}

  printf("%d\n", cnt);

  return 0;
}

int binarySearch(int key){
  int left = 0;
  int right = n;
  int mid;
  while(left < right){
    mid = (left + right) / 2;
    if(Sn[mid] == key) return 1;
    else if(key < Sn[mid]) right = mid;
    else if(key > Sn[mid]) left = mid + 1;
  }
  return 0;
}
