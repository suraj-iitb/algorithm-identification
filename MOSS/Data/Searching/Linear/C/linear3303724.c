#include <stdio.h>

int search(int key, int S[], int n);

int main(){
  int n,q,key,i=0,count=0;
    int S[10000];
    
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }
    i = 0;
    scanf("%d",&q);
    for(i=0;i<q;i++){
      scanf("%d",&key);
      if(search(key, S, n)){
	count++;
      }
    }
    printf("%d\n",count);
    
    return 0;
}

int search(int key, int S[], int n){
  int i = 0;
  S[n] = key;
  while(S[i]!=key){
    i++;
    if(i==n){
      return 0;
    }
  }
  return 1;
}

