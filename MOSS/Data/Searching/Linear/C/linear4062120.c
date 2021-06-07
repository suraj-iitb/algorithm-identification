#include <stdio.h>
int linearSearch(int);

int S[10000];
int n;

int main(){
  int T[500];
  int q;
  int count=0;
  int i;
  int A[500];
  

  scanf("%d",&n);
  
  for(i = 0; i < n; i++){ scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);

  for(i = 0;i< q; i++){
    scanf("%d",&T[i]);
  }

 
  
  for(i = 0; i < q; i++){
    if(linearSearch(T[i])) {
      count++;}
  }
  printf("%d\n",count);
  return 0;
}


int linearSearch(int suuzi){
  int i;
  
  for(i = 0; i < n; i++){
    
    if(S[i] == suuzi) {return 1;}
  }
  return 0;
}


