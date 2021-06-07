#include <stdio.h>

#define MAXS 10000
#define MAXT 500

int search(int *A, int n, int key){

  int left=0;

  int right=n;

  int mid;

  while(left<right){

    mid=(left+right)/2;
   
    if(A[mid]==key) return 1;
    else if(key<A[mid]) right=mid;
    else if(key>A[mid]) left=mid+1;

  }

  return 0;

}


int main(){

  int i,j,k,n,q;

  int cnt=0;

  scanf("%d",&n);

  int S[n];

  for(i=0;i<n;i++){
    
    scanf("%d", &S[i]);

  }

  scanf("%d", &q);

  int T;
  

  for(i=0;i<q;i++){

    scanf("%d", &T);

    if(search(S, n, T)) cnt++;
    
  }

			     
  printf("%d\n",cnt);
  
  return 0;
  
}

