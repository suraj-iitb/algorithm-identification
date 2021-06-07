#include<stdio.h>

#define NMAX 100000

int binarySearch(int);

int N[NMAX],n;

int main(){
  int i,q,a,cnt=0;

  scanf("%d",&n);

  for(i=0; i<n; i++)
    scanf("%d",&N[i]);

  scanf("%d",&q);

  for(i=0; i<q; i++){
    scanf("%d",&a);
    cnt += binarySearch(a);
  }

  printf("%d\n",cnt);

  return 0;
}

int binarySearch(int key){
  int left=0,right=n,mid;

  while(left < right){
    mid = (left + right)/2;
    if(N[mid] == key) return 1;
    else if(key < N[mid]) right = mid;
    else left = mid + 1;
  }
  
  return 0;
}
      
   
    

  

