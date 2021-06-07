#include<stdio.h>
#define NOT_FOUND 0
int binarySearch(int n,int *a,int key){
  int left = 0;
  int right = n;
  int mid;
  while(left < right){
    mid = (left + right) / 2;
    if(a[mid] == key)  return 1;
    else if(key < a[mid])  right = mid;
    else left = mid + 1;
  }
  return NOT_FOUND;
}
int main(){
  int n,a[100000],q,b[50000],i,cnt = 0;
  scanf("%d",&n);
  for(i = 0;i < n; i++){
     scanf("%d",&a[i]);
   }
   scanf("%d",&q);
   for(i = 0;i < q; i++){
     scanf("%d",&b[i]);
   }
   for(i = 0;i < q; i++){
     if(binarySearch(n,a,b[i]) != NOT_FOUND) cnt++;
   }
   printf("%d\n",cnt);
   return 0;
 }

