#include <stdio.h>

void binarySearch(int,int);

int count=0;
int S[100000];

int main(){
   int n,q,i,j;
  int T[100000];

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
    if(T[i] != T[i-1] || i == 0){
    binarySearch(T[i],n);
    }
  }
  printf("%d\n",count);
  return 0;
}
void binarySearch(int key,int n){
  int left = 0;
  int right = n;
  int mid;
  
  while(left < right){
          mid = (left + right) / 2;
	  if(S[mid] == key){
            count++;
	    break;
	  }  
	  else if (key < S[mid])
	  right = mid;
          else
	  left = mid + 1;
  }
}

