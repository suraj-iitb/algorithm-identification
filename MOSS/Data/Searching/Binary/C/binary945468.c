#include<stdio.h>
#define S 1000000
#define T 1000000
int s[S];
int t[T];
int main(){
  int key,right,mid,ave,left,i,j,n,q,count=0;
  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&t[i]);
  }
  right = n;
  left = 0;
  mid =  (right+left)/2;
  key = t[0];
  i = 0;
  while(1){
    if(key == s[mid]){
      count++;
      i++;
      key = t[i];
      right = n;
      left = 0;
      mid =  (right+left)/2; 
    }
    if(left >= right){
      i++;
      key = t[i];
      right = n;
      left = 0;
      mid =  (right+left)/2;
    }
    if(i == q)break;
    if(s[mid] > key){
      right = mid;
      mid = (right + left)/2;
    }
    else if(s[mid] < key){
      left = mid+1;
      mid = (left + right)/2;
    }
  }
  printf("%d\n",count);
  return 0;
}
