#include<stdio.h>
#include<stdlib.h>
#define M 10000


int math(int ,int ,int ,int *);

int main(){
  
  int a,b,S[100001],t=0,i;
  
  scanf("%d",&a);

  for(i=0; i < a; i++){
    
    scanf("%d",&S[i]);
    
  }
  
  scanf("%d",&b);

  while(b--){
    
    scanf("%d",&i);
    
    if(S[math(0,a-1,i,S)]==i){
      
      t++;
      
    }
  }
  
    printf("%d\n",t);

    return 0;

}
int math(int a,int b,int c,int *d){
  
  int s;
  
  s=(a+b)/2;

  if(a==b)return s;
  
  return c <= d[s]?math(a,s,c,d):math(s+1,b,c,d);
}


