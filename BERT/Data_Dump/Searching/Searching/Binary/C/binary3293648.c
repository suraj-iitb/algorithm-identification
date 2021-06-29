#include<stdio.h>
#define N 100000
#define Q 50000

int main(){
  int i, j, n, q, left = 0, right, mid, ans=0, key, S[N], T[Q];
  
   scanf("%d",&n);
  for(i=0 ; i<n ; i++){
  scanf("%d",&S[i]);
  }
  
  scanf("%d",&q);
  for(i=0 ; i<q ; i++){
  scanf("%d",&T[i]);
  }

  for(j=1 ; j<n ; j++){
    key = S[j];
    i = j-1;
    while(i >= 0 && S[i] > key){
      S[i+1] = S[i];
      i = i-1;
    }
    S[i+1] = key;
  }

 

  for(i=0 ; i<q ; i++){
    left = 0;
    right = n;
    
    while(left < right){

      mid = (left + right)/2;

      if(S[mid] == T[i]){
	
      ans++;
      break;
    }
      else if(S[mid] > T[i]){
	right = mid;

      }
      else {
	left = mid + 1;
	
      }
    }
  }
  
  printf("%d\n",ans);
  return 0;
}


