#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int binarySearch(int,int *,int);
int main(){
  int n,q,*S,i,key,cnt=0;
  while(1){
    
    scanf("%d",&n);
    if(n<=pow(10,5)) break;
  }
     S = (int *)malloc((n+1)*sizeof(int));
    for(i=0;i<n;i++){
      scanf("%d",&S[i]);
      if(S[i]<0&&S[i]>pow(10,9)) exit(2);
    }
     while(1){
    
    scanf("%d",&q);
    if(q<=pow(10,4)*5) break;
  }

 for(i=0;i<q;i++){
      scanf("%d",&key);
      if(key<0||key>pow(10,9)) exit(2);
      if(binarySearch(key,S,n)) cnt++;
 }
 printf("%d\n",cnt);
 return 0;
}

int binarySearch(int key,int *S,int n){
  
  int left =0,right=n,mid;

  while(left <right) {
    mid = (left + right)/2;
    if(S[mid] ==key) return 1;
    else if(key<S[mid]) right = mid;
    else left = mid +1;
   
    
  }
  return 0;
  
}

