#include <stdio.h>

int serach(int* a,int b,int c){
  
  int i=0;
  
  a[b]=c;
  
  while(a[i]!=c){
    i++;
  }
  
  if (i==b){
    return 0;
  }
  return 1;
    
}
int main(){
  
  int a[10001],b,c,i,j,s=0;

  scanf("%d",&b);
  for(i=0;i<b;i++){
    
  scanf("%d",&a[i]);

  }
  
  scanf("%d",&j);
  
  for(i=0;i<j;i++){
    
    scanf("%d",&c);
    
    if(serach(a,b,c))s++;
  }

  printf("%d\n",s);

  return 0;
}

