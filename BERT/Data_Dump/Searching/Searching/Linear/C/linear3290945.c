#include<stdio.h>
#define SIZE 1000000

int linearSearch(int s[],int n,int t){
  int i;
  i=0;
  s[n]=t;
  while(s[i]!=t){
    i++;
  }
    if(i==n){
      return 0;
    }
    else {
      return 1;
    }
}
  

int main(){
  int n,i,q,t,s[SIZE],c,count=0;;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }

  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t);
    c=linearSearch(s,n,t);
    if(c==1){
      count++;
    }
  }

  printf("%d\n",count);


  return 0;
}


    
  

