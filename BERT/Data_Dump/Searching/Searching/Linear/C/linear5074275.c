#include<stdio.h>
#include<stdlib.h>
#define N 10000

char linearSearch(int);

int n,q;
int S[N];
int T[N];

int main(){
  int i,j;
  int result=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  scanf("%d",&q);
  for(j=0;j<q;j++){
    scanf("%d",&T[j]);
  }
  for(j=0;j<q;j++){
      if(linearSearch(T[j])=='N') result=result;
      else if(linearSearch(T[j])=='i') result=result+1;
      else result=result;
  }

  printf("%d\n",result);

  return 0;
}

char linearSearch(int T){
  int key;
  int i=0;
  key=T;
  for(i=0;i<n;i++){
    if(S[i] == key) return 'i';
  }
  return 'N';
}
  

  

  
    

