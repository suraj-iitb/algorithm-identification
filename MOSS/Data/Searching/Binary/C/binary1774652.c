#include<stdio.h>
#include<stdlib.h>
#define N 100000
#define M 50000

int binary_search(int);

int n, s[N], q, t[M];

int main(){
  int c=0,i, j;
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
    if( binary_search(t[i])==1)c++;
  }
  printf("%d\n",c);
  return 0;
}
int binary_search(int key){
  int left, right, mid;

  left = 0;
  right = n;
  while( left < right){
    mid = (left + right) / 2;
    if(s[mid] == key) return 1;
    else if(key < s[mid])right = mid;
    else left = mid + 1;
  }
  return 0;
}
	      
