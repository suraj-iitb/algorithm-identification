#include<stdio.h>

int main(int argc,char *argv[]){

  int i,n,q,s[100000],t,min,max,mid,count = 0;

  scanf("%d",&n);
  for(i = 0;i < n;i++)
    scanf("%d",&s[i]);

  scanf("%d",&q);
  while(q--){
    scanf("%d",&t);
    min = 0;
    max = n - 1;
    while(min <= max){
      mid = (min + max) / 2;
      if(t == s[mid]){
	count++;
	break;
      }
      else if(t < s[mid])max = mid - 1;
      else if(t > s[mid])min = mid + 1; 
   }
  }
  printf("%d\n",count);
  return 0;
}
