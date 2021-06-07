
#include<stdio.h>

int linearSerch(int S[],int key,int n){
  int i;
  for(i = 0; i < n; i++){
    if(S[i] == key)
      return 1;
  }
  return 0;
}

    


int main(){
  int i,n,q,key,S[100000],sum=0;
  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &S[i]);
  
  scanf("%d", &q);
  for(i = 0; i < q; i++){
    scanf("%d", &key);
    if(linearSerch(S,key,n))
      sum++;
  }
  

  printf("%d\n", sum);

  return 0;
}



