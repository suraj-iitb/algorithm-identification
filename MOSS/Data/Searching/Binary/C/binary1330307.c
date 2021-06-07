#include <stdio.h>
#include <stdlib.h>
 
int binarySearch(int *, int, int);
 
main(){
  int n,q,i,count=0;
  int *sAry,*tAry;
 
  scanf("%d", &n);
  sAry = malloc(n*sizeof(int));
  for(i=0; i<n; i++) scanf("%d", sAry+i);
  scanf("%d", &q);
  tAry = malloc(q*sizeof(int));
  for(i=0; i<q; i++) scanf("%d", tAry+i);
 
  for(i=0; i<q; i++)
    count += binarySearch(sAry, n, tAry[i]);
 
  printf("%d\n", count);
 
  return 0;
}
 
binarySearch(int *ary, int n, int a){
  int right,mid,left;  //search用
 
  right=n; //右端の１つ後
  left=0; //左端
 
  while(right > left){
    mid = (right+left)/2;
    if(ary[mid] == a) return 1;
    else if(ary[mid] > a) right = mid;
    else if(ary[mid] < a) left = mid +1;
  }
  return 0;
}
