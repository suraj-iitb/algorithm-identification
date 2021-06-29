#include<stdio.h>
#define n 10000
#define q 500

int main(){
  
  int s[n],t[q],c=0,countn,countq,i,j,flag=0;
  
  scanf("%d",&countn);
  for(i = 0; i < countn; i++){
    
    scanf("%d",&s[i]);
  }
  scanf("%d",&countq);
  for(i = 0; i < countq; i++){
    
    scanf("%d",&t[i]);
  }
  for(j = 0; j < countq; j++){
    for(i = 0; i < countn; i++){
      if(s[i] == t[j] && flag == 0){ 
	c++;
      flag = 1;
      }
    }
      flag = 0;
  }
  
  
  printf("%d\n",c);
  
  return 0;
}
