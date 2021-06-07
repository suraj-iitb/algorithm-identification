#include<stdio.h>
 
#define MAX_N 100000
#define MAX_Q 50000
 
int main(void){
 
  int i, j, key, sum, s_n, t_n, s[MAX_N], t[MAX_Q];
 
  scanf("%d",&s_n);
  for(i=0; i<s_n;i++){
    scanf("%d", &s[i]);
  }
 
  scanf("%d",&t_n);
  for(i=0; i<t_n;i++){
    scanf("%d", &t[i]);
  }
 
  sum = 0;
  for(i=0;i<t_n;i++){
    key = t[i];
    int left = 0;
    int right = s_n;
    while(left < right){
      int mid = (int)((left + right) / 2);
       
      if(key == s[mid]){
        sum++;
        break;
      } else if(key > s[mid]){
        left = mid + 1;
      } else {
        right = mid;
      }
    }
  }
 
  printf("%d\n", sum);
 
  return 0;
}

