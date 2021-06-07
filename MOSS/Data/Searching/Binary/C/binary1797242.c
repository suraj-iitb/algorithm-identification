#include<stdio.h>
 
int main(){
 
  int i, left, right, mid, n, q, cnt = 0, s[100000], t[50000] ;

 
  scanf("%d", &n);
  for(i = 0;i < n;i++){
    scanf("%d", &s[i]);
 }
 
  scanf("%d", &q);
  for(i = 0;i < q;i++){
    scanf("%d", &t[i]);
    left = 0;
    right = n;
    while(left < right){
      mid = (left + right) / 2;
      if(t[i] == s[mid]){
        cnt++;
        break;
      }
      if(t[i] > s[mid]){
        left = mid + 1;
      }
      else if(t[i] < s[mid]){
        right = mid;
      }
    }
  }
  printf("%d\n", cnt);
  return 0;
}
