#include<stdio.h>

int linearSearch(int n, int key, int *S){
  
  int i=0;
  
  S[n]=key;
  if(S[0]==key){
    return 1;
  }
    
  while(S[i]!=key){
    i++;
  }
    if(i==n){
      return 0;
    }

  return 1;
}

    
int main(){

  int i,n,q,key,count=0;
  int S[100001];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(linearSearch(n,key,S)){
      count++;
    }
  }

  printf("%d\n",count);

  return 0;
}
 
