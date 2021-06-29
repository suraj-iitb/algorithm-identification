#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int search(int,int *,int);
int main(){
  int n,q,*S,i,key,cnt=0;
  while(1){
    
    scanf("%d",&n);
    if(n<=10000) break;
  }
     S = (int *)malloc((n+1)*sizeof(int));
    for(i=0;i<n;i++){
      scanf("%d",&S[i]);
      if(S[i]<0&&S[i]>pow(10,9)) exit(2);
    }
     while(1){
    
    scanf("%d",&q);
    if(q<=500) break;
  }

 for(i=0;i<q;i++){
      scanf("%d",&key);
      if(key<0||key>pow(10,9)) exit(2);
      if(search(key,S,n)) cnt++;
 }
 printf("%d\n",cnt);
 return 0;
}

int search(int key,int *S,int n){
  int i=0;
  S[n] = key;

  while(S[i] != key) {
    i++;
    // printf("%d  %d\n",S[i],key);
  }
  

  return i != n;
}

