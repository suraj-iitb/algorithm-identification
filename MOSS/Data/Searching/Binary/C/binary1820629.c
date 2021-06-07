#include<stdio.h>
 
#define N 100000
#define Q 50000
 
int BinarySearch(int,int);
 
int S[N];
 
int main()
{
  int T[Q],n,q,i,count = 0;
 
  scanf("%d",&n);
 
  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }
 
  scanf("%d",&q);
 
  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
    count += BinarySearch(n,T[i]);
  }
 
  printf("%d\n",count);
 
  return 0;
}
int BinarySearch(n,key){
	int left = 0;
	int right = n;
	int mid;
	while(left < right){
		
		mid = (left + right) / 2;
	
		if(key == S[mid]) return 1;
	
		if(key > S[mid]) left = mid + 1;
	
		else if(key < S[mid]) right = mid;
	}
	return 0;
}
