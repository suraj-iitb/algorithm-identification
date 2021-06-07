#include <stdio.h>
#define NOT_FOUND -1
int n,q;



int main(){
  int i,a,count=0;
  
  scanf("%d",&n);
  int s[n];

  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  
  scanf("%d",&q);
  int t[q];

  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }

  for(i=0;i<q;i++){
    a = linearSearch(s,t[i]);
    if(a != -1){
      count++;
    }
  }

  printf("%d\n",count);

  return 0;
  
}

int linearSearch(int *A,int key){
  int i;
  i=0;
  A[n]=key;
  while(A[i]!=key){
    i++;
  }
  if(i==n){
    return NOT_FOUND;
  }
  return i;
}
  

  

 

