#include <stdio.h>
#define N 100000

int n,S[N];

int binary(int key){
  int left,m,right;
    left = 0;
    right = n;
    while(left < right){
      m = (left + right)/2;
      if(key == S[m])return 1;
      else if(key > S[m])left = m + 1;
      else if(key < S[m])right = m;
    }
    return NULL;
}

int main(){
  int q,key,i,count = 0;
  
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);
  
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&key);
    if(binary(key)==1)count++;
  }

  printf("%d\n",count);
  
  return 0;
}

