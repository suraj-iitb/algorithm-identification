#include <stdio.h>
#define Ns 100000
#define Nt 50000

int main(){
  
  int n, q, i;
  int S[Ns], T[Nt];
  int left, right, mid, key, count=0;

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &S[i]);
  }
  scanf("%d", &q);
  for(i=0; i<q; i++){
    scanf("%d", &T[i]);
  }

  //left=0; right=n; 
  for(i=0; i<q; i++){
    left=0; right=n; 
    key=T[i];         //printf("key=%d  ", key);
    
    while(left<right){
      mid=(left+right)/2;    //printf("S[mid]=%d\n",S[mid]); 
      if(S[mid]==key) {
	count++;
	//printf("count++\n");
	break;
      }
      if(S[mid]<key){
	left=mid+1;
      }
      if(S[mid]>key){
	right=mid;
	
      }
    }
      
  }

  printf("%d\n", count);
  return 0;
    
}

