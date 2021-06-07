#include<stdio.h>
#define n 100000
#define q 50000

int main(){
  
  int s[n],t[q],c=0,countn,countq,i,j,left,right,mid;
  
  scanf("%d",&countn);
  for(i = 0; i < countn; i++){
    scanf("%d",&s[i]);
  }
  
  scanf("%d",&countq);
  for(i = 0; i < countq; i++){
    
    scanf("%d",&t[i]);
  }
  
  for(i = 0; i < countq; i++){
    left = 0;
    right = countn;
    while(left < right){
      
      mid = (left + right)/2;
      if(t[i] == s[mid]){
	c++;
	break;
      }
      if(t[i] > s[mid]) left = mid + 1;
      else if(t[i] < s[mid]) right = mid;
    }
  }
  
  
  printf("%d\n",c);
  
  return 0;
}
